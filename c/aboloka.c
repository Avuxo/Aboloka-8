#include <stdio.h>

#include "cpu.h"

uint32_t testProgram[] = {
    0x10004005, /*ld $0040, #$05*/
    0x10003230, /*ld $0032, #$30*/
    0x55410000, /*emit $41*/
    0xEA000000  /*exit*/
};


int main(int argc, char **argv){
    struct System *sys = cpu_init();

    cpu_executeProgram(sys, testProgram);
    
    return 0;
}
