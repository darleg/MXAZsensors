#include "mbed.h"
#include "console.h"

static BufferedSerial az(TX, RX);
    FileHandle *mbed::mbed_override_console(int fd)
    {
        return &az;
    }