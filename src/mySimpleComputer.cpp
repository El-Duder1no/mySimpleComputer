#include "mySimpleComputer.h"

int memory[memSize];
int regFlags;
const int commands[] = {0xA, 0xB, 0x14, 0x15, 0x1E, 0x1F, 0x20, 0x21, 0x28, 0x29, 0x2A, 0x2B, 0x33,
                        0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40,
                        0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C};

int sc_memoryInit()
{
    for(int i = 0; i < memSize; i++)
    {
        memory[i] = 0;
    }
    return 0;
}
int sc_memorySet(int address, int value)
{
    if (address >= 0 and address < memSize) {
        memory[address] = value;
        return 0;
    } else {
        sc_regSet(OUT_OF_BOUNDS, 1);
        printf("OUT_OF_BOUNDS_MEMORY\n");
        return -1;
    }
}
int sc_memoryGet(int address, int& value)
{
    if (address >= 0 and address < memSize) {
        value = memory[address];
        return 0;
    } else {
        sc_regSet(OUT_OF_BOUNDS, 1);
        printf("OUT_OF_BOUNDS_MEMORY\n");
        return -1;
    }
}

int sc_memorySave(char* filename)
{
    FILE *write = fopen(filename, "wb+");
    if(write == NULL)
    {
        return -1;
    }
    fwrite(memory, sizeof(int), memSize, write);
    fclose(write);
    return 0;
}
int sc_memoryLoad(char* filename)
{
    FILE * read = fopen(filename, "rb+");
    if(read == NULL)
    {
        return -1;    
    }
    fread(memory, sizeof(int), memSize, read);
    fclose(read);
    return 0;
}

int sc_regInit()
{
    regFlags = 0;
    return 0; 
}
int sc_regSet(int reg, int value)
{
    if (reg >= 1 and reg <= 5) {
        if (value == 0) {
            regFlags &= ~(1 << (reg - 1));
            return 0;
        } else if (value == 1) {
            regFlags |= 1 << (reg - 1);
            return 0;
        } else
            return -1;
    } else
        return -1;
}
int sc_regGet(int reg, int& value)
{
    if (reg >= 1 and reg <= 5) {
        value = ((regFlags >> (reg - 1)) & 0x1);
        return 0;
    } else
        return -1;
}

int cmp(const void *left, const void *right)
{
    return(*(int*)left - *(int*)right);
}
int sc_commandEncode(int command, int operand, int& value)
{
    if (bsearch(&command, commands, commandsSize, sizeof(int), cmp)) {
        value = (command << 7) | operand;
    } else {
        sc_regSet(INVALID_COMMAND, 1);
        printf("INVALID_COMMAND\n");
        return -1;
    }
    return 0;
}
int sc_commandDecode(int& command, int& operand, int value)
{
   int tmpCommand, tmpOperand;

    if (((value >> 14) & 1) == 0) {
        tmpCommand = value >> 7;
        tmpOperand = value & 0x7F;

        if (bsearch(&tmpCommand, commands, commandsSize, sizeof(int), cmp)) {
            command = tmpCommand;
            operand = tmpOperand;
        } else {
            printf("INVALID_COMMAND\n");
            sc_regSet(INVALID_COMMAND, 1);
            return -1;
        }
    } else
        return 1;
    return 0; 
}
