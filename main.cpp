#include "mbed.h"
#include "OnBoard.h"
#include "DevI2C.h"
#include "HTS221Sensor.h"
#include "LPS22HBSensor.h"



#define delay200ms     200ms
#define delay500ms     500ms
#define delay800ms     800ms


PinName SDA = PB_9;
PinName SCL = PB_8;

Thread thread;


static BufferedSerial az(TX, RX);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &az;
}

static DevI2C devI2c(SDA, SCL);

static LPS22HBSensor PressTemp(&devI2c);
static HTS221Sensor HumTemp(&devI2c);

int main()
{
    uint8_t id;
    float temp1, hum, temp2, press;

    /* Init all sensors with default params */
    HumTemp.init(NULL); 
    PressTemp.init(NULL);
    
    /* Enable all sensors */ 
    HumTemp.enable();
    PressTemp.enable();
    
    HumTemp.read_id(&id);
    printf("HTS221  humidity & temperature    = 0x%X\r\n", id);
    PressTemp.read_id(&id);
    printf("LPS22HB pressure & temperature    = 0x%X\r\n", id);
    
    printf("\n\r--- Reading sensor values ---\n\r"); ;
    
    while (true) {
         printf("\r\n");
         
         HumTemp.get_temperature(&temp1);
         HumTemp.get_humidity(&hum);
         printf("HTS221:\r\n");
         printf("Temp: %.2f C\r\n", temp1);
         printf("Hum: %.2f %%\r\n", hum);
         
         ThisThread:: sleep_for(delay500ms);
         
         PressTemp.get_temperature(&temp2);
         PressTemp.get_pressure(&press);
         printf("LPS22HB:\r\n");
         printf("Temp: %f.2 C\r\n", temp2);
         printf("Press: %.2f mbar\r\n", press);
         printf("---\r\n");
         
         ThisThread::sleep_for(delay800ms);

    }
}

