#include "printConsole.h"

void printBoxes()
{
    gotoXY(1,1);
    std::cout << "                    ";

    printBox(2, 2, 11, 61);
    printBox(2, 64, 2, 22);
    printBox(5, 64, 2, 22);
    printBox(8, 64, 2, 22);
    printBox(11, 64, 2, 22);
    
    printBox(14, 2, 9, 45);
    printBox(14, 49, 9, 37);

    gotoXY(2, 29);
    std::cout << " Memory ";
    gotoXY(2, 69);
    std::cout << " Accumulator ";
    gotoXY(5, 65);
    std::cout << " Instruction Counter ";
    gotoXY(8, 70);
    std::cout << " Operation ";
    gotoXY(11, 72);
    std::cout << " Flags ";
    gotoXY(14, 50);
    std::cout << " Keys ";

    printKeys();
}

void printKeys()
{
    gotoXY(15, 51);
    std::cout << "l  - load";
    gotoXY(16, 51);
    std::cout << "s  - save";
    gotoXY(17, 51);
    std::cout << "r  - run";
    gotoXY(18, 51);
    std::cout << "t  - step";
    gotoXY(19, 51);
    std::cout << "i  - reset";
    gotoXY(20, 51);
    std::cout << "F5 - accumulator";
    gotoXY(21, 51);
    std::cout << "F6 - instructionCounter";
}

void printFlags()
{
    int flags[5];
    char flagsChar[5] {' '};

    myComputer PC;

    PC.regGet(myComputer::OPERATION_OVERFLOW, flags[0]);
    PC.regGet(myComputer::DIVISION_BY_ZERO, flags[1]);
    PC.regGet(myComputer::OUT_OF_BOUNDS, flags[2]);
    PC.regGet(myComputer::CLOCK_PULSE_IGNORE, flags[3]);
    PC.regGet(myComputer::INVALID_COMMAND, flags[4]);

    if(flags[0] == 1)
        flagsChar[0] = 'P';
    if(flags[1] == 1)
        flagsChar[1] = '0';
    if(flags[2] == 1)
        flagsChar[2] = 'M';
    if(flags[3] == 1)
        flagsChar[3] = 'T';
    if(flags[4] == 1)
        flagsChar[4] = 'E';

    gotoXY(12, 69);
    std::cout << flagsChar[0] << "  " 
              << flagsChar[1] << "  " 
              << flagsChar[2] << "  " 
              << flagsChar[3] << "  " 
              << flagsChar[4];
}

void printMemory()
{
    myComputer PC;
    int val;
    
    for(int i = 0; i < 10; i++)
    {
        gotoXY(3 + i, 3);
        for(int j = 0; j < 10; j++)
        {
            if(j != 0)
                std::cout << " ";
            PC.memoryGet(i * 10 + j, val);
            if(val < 0)
                printf("-%.4X", -val);
            else
                printf("+%.4X", -val);
        }
    }
    std::cout << "\n";
}

void printBigChars(myBigChar::BigChar sign, std::array<myBigChar::BigChar, 4> chars)
{
    myBigChar s(sign);
    s.print(14, 3, Colors::WHITE, Colors::BLACK);

    myBigChar arr[4] = {chars[0], chars[1], chars[2], chars[3]};

    for(int i = 0, y = 11; i < 4; i++, y += 9)
    {
        arr[i].print(14, y, Colors::WHITE, Colors::BLACK);
    }
}

void printAll(myBigChar::BigChar sign, std::array<myBigChar::BigChar, 4> chars)
{
    printBoxes();
    printFlags();
    printMemory();
    printBigChars(sign, chars);
    gotoXY(26, 1);
}

void runConsole(myBigChar::BigChar sign, std::array<myBigChar::BigChar, 4> chars)
{
	Keys key = Keys::None;
	myComputer PC;
	
	printAll(sign, chars);
	
	while(key != Keys::Quit)
	{
		readkey(key);
		switch(key)
		{
		case Keys::Up:
			break;
		case Keys::Down:
			break;
		case Keys::Left:
			break;
		case Keys::Right:
			break;
		case Keys::Load:
			PC.memoryLoad("../res/RAM.dat");
			break;
		case Keys::Save:
			PC.memorySave("../res/RAM.dat");
			break;
		case Keys::F5:
			break;
		case Keys::F6:
			break;
		case Keys::Run:
			break;
		case Keys::Step:
			break;
		case Keys::Reset:
			break;
		default:
			break;
			
		}
	}
}

