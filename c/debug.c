#include <stdio.h>

#include "debug.h"

/*
                 ===! UH OH, HACK ALERT !===
  
  This code is NOT for use in the actual Aboloka-8 source code
  and is intended for use ONLY in the testing stage while the
  code is in the console stage being tested in a terminal.
  This code uses libc print functions and does NOT call display
  drawing functions.

  Furthermore, it contains UNSAFE code in printProgramSegment()
  because that code has array indexing WITHOUT bounds checking
  that makes the extremely naive assumption that uint8_t program
  is of size n*8. Later on, these functions will be replaced
  with system callable functions so that a proper debugger can
  be implemented inside of the Aboloka-8.

  These functions are TEMPORARY, this code should NEVER be seen
  outside of the pre-SDL build. 
  

*/

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
