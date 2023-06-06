#include "oneRGB3LEDs.h"

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