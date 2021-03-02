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

	int zero[2]   = 	{ 572'660'736, 471'999'010 };
    int one[2]    = 	{ 134'876'160, 1'040'713'736 };
    int two[2]    = 	{ 269'487'616, 503'448'584 };
    int three[2]  = 	{ 269'487'616, 235'933'708 };
    int four[2]   = 	{ 337'121'280, 269'499'922 };
    int five[2]   = 	{ 33'693'184,  235'933'710 };
    int six[2] 	  = 	{ 33'830'912,  472'000'026 };
    int seven[2]  = 	{ 269'499'904, 33'817'608 };
    int eight[2] =		{ 304'225'280, 471'999'004 };
    int nine[2]   =		{ 572'660'736, 235'937'852 };
    
    printBigChar(zero, 10, 6, Colors::WHITE, Colors::BLACK);
    printBox(10, 5, 9, 9);
    printBigChar(one, 10, 16, Colors::WHITE, Colors::BLACK);
    printBox(10, 15, 9, 9);
    printBigChar(two, 10, 26, Colors::WHITE, Colors::BLACK);
    printBox(10, 25, 9, 9);
    printBigChar(three, 10, 36, Colors::WHITE, Colors::BLACK);
    printBox(10, 35, 9, 9);
    printBigChar(four, 10, 46, Colors::WHITE, Colors::BLACK);
    printBox(10, 45, 9, 9);
    
    printBigChar(five, 25, 6, Colors::WHITE, Colors::BLACK);
    printBox(25, 5, 9, 9);
    printBigChar(six, 25, 16, Colors::WHITE, Colors::BLACK);
    printBox(25, 15, 9, 9);
    printBigChar(seven, 25, 26, Colors::WHITE, Colors::BLACK);
    printBox(25, 25, 9, 9);
    printBigChar(eight, 25, 36, Colors::WHITE, Colors::BLACK);
    printBox(25, 35, 9, 9);
    printBigChar(nine, 25, 46, Colors::WHITE, Colors::BLACK);
    printBox(25, 45, 9, 9);

    return 0;
}
