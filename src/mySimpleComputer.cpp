#include "mySimpleComputer.h"

int memory[size];
int regFlags;

int sc_memoryInit()
{
    for (int i = 0; i < size; i++) {
        memory[i] = 0;
    }
    return 0;
}

int sc_memorySet(int address, int value)
{
    if (address >= 0 and address < size) {
        memory[address] = value;
        return 0;
    } else {
        sc_regSet(OUT_OF_BOUNDS, 1);
        std::cout << "OUT_OF_BOUNDS_MEMORY\n";
        return -1;
    }
}
int sc_memoryGet(int address, int& value)
{
    if (address >= 0 and address < size) {
        value = memory[address];
        return 0;
    } else {
        sc_regSet(OUT_OF_BOUNDS, 1);
        std::cout << "OUT_OF_BOUNDS_MEMORY\n";
        return -1;
    }
}

int sc_memorySave(char* filename)
{
    std::ofstream write(filename, std::ios::binary | std::ios::trunc);

    if (!write.is_open()) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        write.write((char*)&memory[i], sizeof(memory[i]));
    }

    write.close();
    return 0;
}
int sc_memoryLoad(char* filename)
{
    std::ifstream read(filename, std::ios::binary);

    if (!read.is_open()) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        read.read((char*)&memory[i], sizeof(memory[i]));
    }

    read.close();
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

int sc_commandEncode(int command, int operand, int* value)
{
    bool flag = false;
    int commandCode = 0;
    if (!binary_search(commands, commands + commandsArrSize, command)) {
        sc_regSet(5, 1);
        std::cout << "INVALID_COMMAND\n";
        return -1;
    } else if (operand >= 0 && operand <= size) {
        //кодирование команды и присваивание переменной value
    } else {
        sc_regSet(OUT_OF_BOUNDS, 1);
        std::cout << "OUT_OF_BOUNDS_MEMORY\n";
        return -1;
    }
    return 0;
}

int sc_commandDecode(int* command, int* operand, int value)
{
    return 0;
}
