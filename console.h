#include "mbed.h"

#define TX PA_11
#define RX PA_12

#define clrscn printf("\033[2J\033[;H")
#define poscur(row,col) printf("\033[%d;%dH",row,col)
#define deftxt printf("\033[0m")
#define Tab printf("\t")
enum attr {rst, bld, dim};
enum fg {fgblk=30, fgred=31, fggrn=32, fgyel=33, fgblu=34};
enum bg {bgblk=40, bgred=41, bggrn=42, bgyel=43, bgblu=44};
#define setfgbb printf("\033[%d;%d;%dm", bld, fggrn, bgblu)
#define halfline printf("************************")
#define blankLine printf("\n\t*\t\t\t\t\t\t*");

static BufferedSerial az(TX, RX);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &az;
}