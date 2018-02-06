#include "cpu.h"

/*create a cpu object*/
struct System initCPU(){
    struct System sys;

    /*0 out CPU struct*/
    sys.cpu.pc = 0;
    sys.cpu.regA = 0;
    sys.cpu.regX = 0;
    sys.cpu.regY = 0;
    sys.cpu.regZ = 0;


    return sys;
    
}


/*execute a given program*/
void executeProgram(struct System sys, int8_t *program){
    /*execute each opcode until 'exit' (0xEA) is reached*/
    while(program[sys.cpu.pc] != 0xEA){
        
        /*switch statement for opcodes*/
        switch(program[sys.cpu.pc]){
        case 0x10:
            /*load the value into memory*/
            sys.memory[program[++sys.cpu.pc]] = program[++sys.cpu.pc];
            break;
        case 0x11:
            /*load the value into the X register*/
            sys.cpu.regX = program[++sys.cpu.pc];
            break;
        case 0x12:
            /*load the value into the Y register*/
            sys.cpu.regY = program[++sys.cpu.pc];
            break;
        case 0x13:
            /*load the value into the Z register*/
            sys.cpu.regZ = program[++sys.cpu.pc];
            break;
        case 0x14:
            /*load the value into the accumulator*/
            sys.cpu.regA = program[++sys.cpu.pc];
            break;
        case 0x20:
            /*jump to the next location*/
            sys.cpu.pc = program[++sys.cpu.pc];
            break;
        case 0x21:
            /*jump to the given GP register (x-z)*/
            break;
        }
    }
}
