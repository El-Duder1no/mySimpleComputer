#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>

class myComputer
{
protected:
    int regFlags;
    std::array<int, 100> memory;
    const std::array<int, 38> commands
    {
        0xA,  0xB,  
        0x14, 0x15, 
        0x1E, 0x1F, 0x20, 0x21, 
        0x28, 0x29, 0x2A, 0x2B, 
        0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 
        0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C
    };
    
public:
    myComputer();

    enum Flag
    {
        OPERATION_OVERFLOW = 1,
        DIVISION_BY_ZERO,
        OUT_OF_BOUNDS,
        CLOCK_PULSE_IGNORE,
        INVALID_COMMAND
    };

    int memorySize();    
    int memoryInit();
    int memorySet(int address, int value);
    int memoryGet(int address, int &value);
    int memorySave(const char* filename);
    int memoryLoad(const char* filename);
    
    int regInit();
    int regSet(int reg, int value);
    int regGet(int reg, int &value);
    
    int commandEncode(int command, int operand, int& value);
    int commandDecode(int &command, int &operand, int value);
};

#endif
