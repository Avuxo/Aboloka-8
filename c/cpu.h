#include <stdint.h>

struct CPU{
    /*program counter*/
    int8_t pc;

    /*registers*/
    int8_t regA;
    int8_t regX;
    int8_t regY;
    int8_t regZ;
};

struct Tape{
    /*storage*/
    int8_t storage[54000];
}

struct System{
    struct CPU cpu;

    /*64kb of memory*/
    int8_t memory[64000];

    /*tapes*/
    struct Tape tapeDrive[2];

    /*16kb of storage*/
    int8_t storage[16000];

    /*TODO: implement display*/
};


struct System initCPU();
void executeProgram();
