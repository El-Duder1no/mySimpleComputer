#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include <fstream>
#include <iostream>

#define size 100

#define OPERATION_OVERFLOW 1
#define DIVISION_BY_ZERO 2
#define OUT_OF_BOUNDS 3
#define CLOCK_PULSE_IGNORE 4
#define INVALID_COMMAND 5

extern int memory[size];
extern int regFlags;
extern int commands[]
        = {0x10, 0x11, 0x20, 0x21, 0x30, 0x31, 0x32, 0x33, 0x40, 0x41,
           0x42, 0x43, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
           0x59, 0x60, 0x61, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
           0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76};

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int& value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit();
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int& value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandEncode(int* command, int* operand, int value);

#endif
