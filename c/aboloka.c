#include <stdio.h>

#include "cpu.h"

uint32_t testProgram[] = {
    0x10004005,
    0x10003230,
    0x55410000,
    0xEA000000
};


int main(int argc, char **argv){
    struct System *sys = initCPU();

    cpu_executeProgram(sys, testProgram);
    
    return 0;
}
