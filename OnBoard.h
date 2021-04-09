#include "mbed.h"

// Renaming Ports on EMW3166 for Onboard AZ3166 RGB and LEDs
#define RedRGB    PB_4
#define GreenRGB  PB_3
#define BlueRGB   PC_7

#define led1 PB_2
#define led2 PA_15
#define led3 PC_13

#define TX PA_11
#define RX PA_12


// Blinking rate in milliseconds
//#define delay200ms     200ms
//#define delay500ms     500ms
//#define delay800ms     800ms


//RGB LED class using three PWM outputs
class RGB
{
public:
    RGB(PinName redrgb, PinName greenrgb, PinName bluergb);
    void RGBcolor(float redled,float greenled, float blueled);
private:
    PwmOut RGBR;
    PwmOut RGBG;
    PwmOut RGBB;
};
 
RGB::RGB (PinName redrgb, PinName greenrgb, PinName bluergb)
    : RGBR(redrgb), RGBG(greenrgb), RGBB(bluergb)
{
    
}
 
void RGB::RGBcolor(float redled,float greenled, float blueled)
{
    RGBR = redled;
    RGBG = greenled;
    RGBB = blueled;
}
