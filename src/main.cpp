#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "printConsole.h"

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
    
    /*
	long int zero[2]   = 	{ 3'890'741'118, 2'130'700'263};
    long int one[2]    = 	{ 943'602'744, 943'208'504 };
    long int two[2]    = 	{ 1'894'252'414, 4'294'903'580 };
    long int three[2]  = 	{ 2'145'451'903, 2'147'475'680 };
    long int four[2]   = 	{ 4'286'019'447, 1'886'417'151 };
    long int five[2]   = 	{ 2'131'230'719, 2'130'698'495 };
    long int six[2]    = 	{ 2'131'230'590, 2'130'700'287 };
    long int seven[2]  = 	{ 1'893'793'791, 471'604'280 };
    long int eight[2]  =	{ 2'129'133'438, 2'129'127'399 };
    long int nine[2]   =	{ 4'293'394'302, 2'130'698'494 };
	long int plus[2]   =    { 2'115'508'224, 1'579'134 };
    long int minus[2]  =	{ 2'113'929'216, 126 };
    
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
    printBigChar(plus, 10, 56, Colors::WHITE, Colors::BLACK);
    printBox(10, 55, 9, 9);
    
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
    printBigChar(minus, 25, 56, Colors::WHITE, Colors::BLACK);
    printBox(25, 55, 9, 9);
    */
    

    /*myBigChar zero(myBigChar::BigChar::Zero),   one(myBigChar::BigChar::One),      two(myBigChar::BigChar::Two),
              three(myBigChar::BigChar::Three), four(myBigChar::BigChar::Four),    five(myBigChar::BigChar::Five),
              six(myBigChar::BigChar::Six),     seven(myBigChar::BigChar::Seven),  eight(myBigChar::BigChar::Eight),
              nine(myBigChar::BigChar::Nine),   plus(myBigChar::BigChar::Plus),    minus(myBigChar::BigChar::Minus);

    zero.print(2, 3, Colors::WHITE, Colors::BLACK);
    one.print(2, 12, Colors::WHITE, Colors::BLACK);
    two.print(2, 21, Colors::WHITE, Colors::BLACK);
    three.print(2, 30, Colors::WHITE, Colors::BLACK);
    four.print(2, 39, Colors::WHITE, Colors::BLACK);
    plus.print(2, 48, Colors::WHITE, Colors::BLACK);

    five.print(11, 3, Colors::WHITE, Colors::BLACK);
    six.print(11, 12, Colors::WHITE, Colors::BLACK);
    seven.print(11, 21, Colors::WHITE, Colors::BLACK);
    eight.print(11, 30, Colors::WHITE, Colors::BLACK);
    nine.print(11, 39, Colors::WHITE, Colors::BLACK);
    minus.print(11, 48, Colors::WHITE, Colors::BLACK);
    
    zero.printBox(2, 2, 18, 54);

    gotoXY(21, 1);*/
    
    printBoxes();
    
    return 0;
}
