#include <stdio.h>

#include "debug.h"

struct Debugger initDebugger(uint8_t *program, struct System *sys){
    struct Debugger debug = {sys, program, 0x08};
    return debug;
}

void printRegisters(struct Debugger debug){
    printf("Registers\n========\nA: 0x%x\nX: 0x%x\nY 0x%x\n Z 0x%x\n\n",
           debug.sys->cpu.regA, debug.sys->cpu.regX,
           debug.sys->cpu.regY, debug.sys->cpu.regZ);
}

void printProgramSegment(struct Debugger debug, int startPoint, int numLines){
    /*NOTE:
      unsafe code, does not contain bounds checking*/
    for(int i=0; i<numLines; i++){
        printf("%d |",startPoint + i);
        for(int j=0; j<debug.opcodesPerLine; j++){
            printf(" %x", debug.program[i * j]);
        }
        printf("\n");
    }
   
}
