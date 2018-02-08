#include <stdio.h>

#include "cpu.h"

uint8_t testProgram[] = {0x10, 0x00, 0x40, 0x05, /*ld #4000, $05*/
                         0x10, 0x00, 0x32, 0x30, /*ld #3200, $30*/
                         0x55, 0x41, /*emit #$41*/
                         
                         0xEA /*exit*/
};


int main(int argc, char **argv){
    struct System *sys = initCPU();

    executeProgram(sys, testProgram);
    
    
    return 0;
}
