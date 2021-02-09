#include "mySimpleComputer.h"
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(nullptr));

    int val;
    char* file = new char[8]{'R', 'A', 'M', '.', 'd', 'a', 't', '\0'};

    sc_memoryInit();
    sc_memoryLoad(file);

    for (int i = 0; i < memSize; i++) {
        sc_memoryGet(i, val);
        printf("%-5d", val);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");

    sc_regInit();
    sc_regSet(OPERATION_OVERFLOW, 0);
    sc_regSet(DIVISION_BY_ZERO, 1);
    sc_regSet(OUT_OF_BOUNDS, 1);
    sc_regSet(CLOCK_PULSE_IGNORE, 0);
    sc_regSet(INVALID_COMMAND, 0);

    for (int i = 1; i <= 5; i++) {
        sc_regGet(i, val);
        printf("reg %d \n", val);
    }

    int command = 0xA, operand = memory[50];
    printf("\nCommand - %d\nOperand - %d\n", command, operand);
    sc_commandEncode(command, operand, val);
    sc_commandDecode(command, operand, val);
    printf("\nCommand - %d\nOperand - %d\n", command, operand);

    return 0;
}
