#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include <iostream>
#include <fstream>

#define size 100;

int memory[size];
int reg;

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit();
int sc_regSet(int register, int value);
int sc_regGet(int register, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandEncode(int* command, int* operand, int value);

#endif
