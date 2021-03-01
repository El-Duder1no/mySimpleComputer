#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    srand(time(nullptr));

    /*
    int val;
    myComputer PC;

    PC.memoryLoad("res/RAM.dat");
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

    int rows, cols;
    getScreenSize(rows, cols);
    cout<< "rows: " << rows << "\tcols: " << cols << "\n";

    cout << "\nPress any key to clear the screen\n";
    cin.get();
    clrscr();
    */

    gotoXY(5, 10);
    setBGColor(Colors::BLACK);
    setFGColor(Colors::RED);
    cout << "Удовченко А.Е.\tКремлякова И.Д.\n";

    gotoXY(6, 8);
    setBGColor(Colors::WHITE);
    setFGColor(Colors::GREEN);
    cout << "ИП-912\n";

    cout << "\E[0m";

    cout << "\nPress any key to clear the screen\n";
    cin.get();
    clrscr();

    int one[2] = { 809'252'912, 808'464'432 };
    printBox(10, 5, 9, 9);
    printBigChar(one, 10, 6, Colors::WHITE, Colors::BLACK);

    return 0;
}
