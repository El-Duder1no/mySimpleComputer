#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>

class myComputer
{
protected:
    std::array<int, 100> memory;
    int regFlags;
    
public:
    myComputer();
    myComputer(const char* filename);
    
    int memoryInit();
    int memorySet(int address, int value);
    int memoryGet(int address, int &value);
    int memorySave();
    int memoryLoad();
    
    int regInit();
    int regSet(int reg, int value);
    int regGet(int reg, int &value);
    
    int commandEncode(int command, int operand, int& value);
    int commandEncode(int &command, int &operand, int value);
};



#define memSize 100
#define commandsSize 38

#define OPERATION_OVERFLOW  1
#define DIVISION_BY_ZERO    2
#define OUT_OF_BOUNDS       3
#define CLOCK_PULSE_IGNORE  4
#define INVALID_COMMAND     5

/*
extern int memory[memSize];
extern int regFlags;
extern const int commands[];

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int& value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit();
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int& value);
int cmp(const void *left, const void *right);
int sc_commandEncode(int command, int operand, int& value);
int sc_commandDecode(int& command, int& operand, int value);*/

#endif
