#include <stdint.h>

struct CPU{
    /*program counter*/
    uint8_t pc;

    /*registers*/
    uint8_t regA;
    uint8_t regX;
    uint8_t regY;
    uint8_t regZ;

    uint8_t flags;
};

struct Tape{
    /*storage*/
    uint8_t storage[54000];
};

struct System{
    struct CPU cpu;
    
    /*64kb of memory*/
    uint8_t memory[64000];

    /*tapes*/
    struct Tape tapeDrive[2];

    /*16kb of storage*/
    uint8_t storage[16000];

    /*TODO: implement display*/
};


struct System *initCPU();
void executeProgram(struct System *sys, uint8_t *program);

void cpu_load(struct System *sys, uint8_t addrB1, uint8_t addrB2, uint8_t val);
