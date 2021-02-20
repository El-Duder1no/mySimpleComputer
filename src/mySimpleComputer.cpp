#include "mySimpleComputer.h"

myComputer::myComputer() : regFlags(0), memory() {}

int myComputer::memorySize()
{
    return memory.size();
}
int myComputer::memoryInit()
{
    memory.fill(0);
    return 0;
}
int myComputer::memorySet(int address, int value)
{
    if (address >= 0 and address < (int)memory.size()) 
    {
        memory[address] = value;
        return 0;
    }
    else 
    {
        regSet(myComputer::OUT_OF_BOUNDS, 1);
        std::cout << "OUT_OF_BOUNDS_MEMORY\n";
        return -1;
    }
}
int myComputer::memoryGet(int address, int& value)
{
    if (address >= 0 and address < (int)memory.size()) 
    {
        value = memory[address];
        return 0;
    } 
    else 
    {
        regSet(myComputer::OUT_OF_BOUNDS, 1);
        std::cout << "OUT_OF_BOUNDS_MEMORY\n";
        return -1;
    }
}

int myComputer::memorySave(const char* filename)
{
    std::ofstream save(filename, std::ios::binary | std::ios::trunc);
    if(!save.is_open())
        return -1;

    for(int i = 0; i < (int)memory.size(); i++)
        save.write((char*)&memory[i], sizeof(memory[i]));
    save.close();

    return 0;
}
int myComputer::memoryLoad(const char* filename)
{
    std::ifstream load(filename, std::ios::binary);
    if(!load.is_open())
        return -1;
    
    for(int i = 0; i < (int)memory.size(); i++)
        load.read((char*)&memory[i], sizeof(memory[i]));
    load.close();

    return 0;
}

int myComputer::regInit()
{
    regFlags = 0;
    return 0; 
}
int myComputer::regSet(int reg, int value)
{
    if (reg >= 1 and reg <= 5) 
    {
        switch(value)
        {
        case 0:
            regFlags &= ~(1 << (reg - 1));
            return 0;
        case 1:
            regFlags |= 1 << (reg - 1);
            return 0;
        default:
            return -1;
        }
    } 
    else
        return -1;
}
int myComputer::regGet(int reg, int& value)
{
    if (reg >= 1 and reg <= 5) 
    {
        value = ((regFlags >> (reg - 1)) & 0x1);
        return 0;
    } 
    else
        return -1;
}

int myComputer::commandEncode(int command, int operand, int& value)
{
    if(operand <= 0x7F)
    {
        if (std::binary_search(commands.begin(), commands.end(), command)) 
        {
            value = (command << 7) | operand;
            return 0;
        } 
        else 
        {
            regSet(myComputer::INVALID_COMMAND, 1);
            std::cout << "Encode - INVALID_COMMAND\n";
            return -1;
        }
    }
    else
        return -1;
}
int myComputer::commandDecode(int& command, int& operand, int value)
{
   int tmpCommand, tmpOperand;

    if (((value >> 14) & 1) == 0) 
    {
        tmpCommand = value >> 7;
        tmpOperand = value & 0x7F;

        if (std::binary_search(commands.begin(), commands.end(), tmpCommand)) 
        {
            command = tmpCommand;
            operand = tmpOperand;
            return 0;
        } 
        else 
        {
            std::cout << "Decode - INVALID_COMMAND\n";
            regSet(myComputer::INVALID_COMMAND, 1);
            return -1;
        }
    } 
    else
        return 1;
}