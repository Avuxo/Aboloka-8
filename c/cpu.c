#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

/*create a cpu object*/
struct System *cpu_init(){
    struct System *sys = (struct System *) malloc(sizeof(sys));

    /*0 out CPU struct*/
    sys->cpu.pc   = 0x00;
    sys->cpu.regA = 0x00;
    sys->cpu.regX = 0x00;
    sys->cpu.regY = 0x00;
    sys->cpu.regZ = 0x00;


    return sys;
    
}

void cpu_executeProgram(struct System *sys, uint32_t *program){
    /*while the current operation is not EXIT*/
    while(program[sys->cpu.pc] != 0xEA000000){
        cpu_execOpcode(sys, program[sys->cpu.pc]);
        sys->cpu.pc++;
    }
}

void cpu_execOpcode(struct System *sys, uint32_t opcode){
    uint8_t operands[4];
    /*NOTE:
      Although it may seem counter intuitive, the first byte of the operation
      is operand[3] because of the bit order on x86. This is easier in my mind
      than reversing the bit order for all opcodes.
      The bit pattern is represented as
      OP A1 A2 A3
      3  2  1  0
     */
    for(int i=0; i<4; i++)
        /*calculate the nth byte in the opcode*/
        operands[i] = (opcode >> (8 * i)) & 0xFF;
    
    
    printf("0x%x | %02x %02x %02x %02x\n", opcode,
           operands[3], operands[2], operands[1], operands[0]);

    switch(operands[3]){
    case 0x10: /*ld*/
        cpu_load(sys, operands[2], operands[1], operands[0]);
        break;
    case 0x11: /*ldx*/
        sys->cpu.regX = operands[2];
        break;
    case 0x12: /*ldy*/
        sys->cpu.regY = operands[2];
        break;
    case 0x13:
        sys->cpu.regZ = operands[2];
        break;
    case 0x14:
        sys->cpu.regA = operands[2];
        break;
    case 0x1A:
        if(sys->cpu.regA == operands[2])
            /*set the eq flag*/
            sys->cpu.flags |= 0x01;
        break;
    case 0x1B:
        /*check if the address is the same as the A value*/
        if(sys->cpu.regA ==
           /*apply 16 bit bitmask to get address*/
           sys->memory[(opcode >> (8)) & 0xFFFF])
            /*set the eq flag*/
            sys->cpu.flags |= 0x01;
        break;
    case 0x20:
        /*apply 16 bit bitmask to get the address*/
        sys->cpu.pc = (opcode >> (8) & 0xFFFF);
        break;
    case 0x22:
        /*check for eq flag*/
        if(((sys->cpu.flags) & 0x01) == 0x01)
            /*jump to 16 bit address*/
            sys->cpu.pc = (opcode >> (8) & 0xFFFF);

    case 0x40:
        /*clear all CPU flags*/
        sys->cpu.flags = 0x00;
    case 0x55:
        
        printf("%c\n", operands[2]);
    }
}

/*load value into memory*/
void cpu_load(struct System *sys, uint8_t addrB1, uint8_t addrB2, uint8_t val){
    /*comine the first two bytes into a single 16 bit address*/
    uint16_t address = addrB1 | (addrB2 << 8);
    /*load val into address*/
    sys->memory[address] = val;
}

