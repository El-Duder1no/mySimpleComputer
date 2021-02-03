#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include <iostream>
#include <fstream>

#define size 100

#define OPERATION_OVERFLOW  1
#define DIVISION_BY_ZERO    2
#define OUT_OF_BOUNDS       3
#define CLOCK_PULSE_IGNORE  4
#define INVALID_COMMAND     5

extern int memory[size];
extern int regFlags;

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
