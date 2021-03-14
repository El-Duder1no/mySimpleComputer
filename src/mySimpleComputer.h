#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>

class myComputer
{
protected:
    static int regFlags;
    static std::array<int, 100> memory;
    const static std::array<int, 38> commands;
    
public:
    enum Flag
    {
        OPERATION_OVERFLOW = 1, // P
        DIVISION_BY_ZERO,       // 0
        OUT_OF_BOUNDS,          // M
        CLOCK_PULSE_IGNORE,     // T
        INVALID_COMMAND         // E
    };
    myComputer();
    
    int memorySize();    
    int memoryInit();
    int memorySet(int address, int value);
    int memoryGet(int address, int &value);
    int memorySave(const char* filename);
    int memoryLoad(const char* filename);
    
    int regSet(int reg, int value);
    int regGet(int reg, int &value);
    
    int commandEncode(int command, int operand, int& value);
    int commandDecode(int &command, int &operand, int value);
};

#endif
