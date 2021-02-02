#include "mySimpleComputer.h"

int sc_memoryInit()
{
    for(int i = 0; i < size; i++)
    {
        memory[i] = 0;
    }
    return 0;
}

int sc_memorySet(int address, int value)
{
    if(address <= 0 and address < size)
    {
        memory[address] = value;
        return 0;
    }
    else
    {
        std::cout << "OUT_OF_BOUNDS_MEMORY\n"
        return -1;
    }
}
int sc_memoryGet(int address, int* value)
{
    if(address <= 0 and address < size)
    {
        value = memory[address];
        return 0;
    }
    else
    {
        std::cout << "OUT_OF_BOUNDS_MEMORY\n"
        return -1;
    }
}

int sc_memorySave(char* filename)
{
    std::ofstream write(filename, std::ios::binary, std::ios::trunc);

    if(!write.is_open())
    {
        return -1;
    }

    for(int i = 0; i < size; i++)
    {
       write.write((char*)&memory[i], sizeof(memory[i])); 
    }

    write.close();
    return 0;
}

int sc_memoryLoad(char* filename)
{
    std::ifstream read(filename, std::ios::binary);

    if(!read.is_open())
    {
        return -1;
    }

    for(int i = 0; i < size; i++)
    {
       read.read((char*)&memory[i], sizeof(memory[i])); 
    }

    read.close();
    return 0;
}
int sc_regInit()
{
    reg = 0;
    return 0;
}

int sc_regSet(int register, int value)
{
    return 0;
}

int sc_regGet(int register, int* value)
{
    return 0;
}

int sc_commandEncode(int command, int operand, int* value)
{
    return 0;
}

int sc_commandEncode(int* command, int* operand, int value)
{
    return 0;
}
