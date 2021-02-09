#include "mySimpleComputer.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    srand(time(nullptr));

    int val;
    myComputer PC;

    PC.memoryLoad("RAM.dat");
    for(int i = 0; i < PC.memorySize(); i++)
    {
        PC.memoryGet(i, val);
        cout << setw(5) << left << val;
        if((i + 1) % 10 == 0)
            cout << "\n";
    }
    cout << "\n";

    PC.regSet(myComputer::OPERATION_OVERFLOW,   1);
    PC.regSet(myComputer::DIVISION_BY_ZERO,     0);
    PC.regSet(myComputer::OUT_OF_BOUNDS,        1);
    PC.regSet(myComputer::CLOCK_PULSE_IGNORE,   0);
    PC.regSet(myComputer::INVALID_COMMAND,      1);

    for (int i = 1; i < 6; i++)
    {
        PC.regGet(i, val);
        cout << "Register " << i << " = " << val << "\n";
    }

    int command = 0xB, operand = 119;
    cout << "\nCommand = " << command << "\tOperand = " << operand << "\n";
    PC.commandEncode(command, operand, val);
    PC.commandDecode(command, operand, val);
    cout << "Command = " << command << "\tOperand = " << operand << "\n";

    return 0;
}
