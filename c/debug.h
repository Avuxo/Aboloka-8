#include "cpu.h"

struct Debugger{
    struct System *sys;
    uint8_t *program;
    uint8_t opcodesPerLine;
};

void printRegisters(struct Debugger debug);
void printProgramSegment(struct Debugger debug, int startPoint, int numLines);
