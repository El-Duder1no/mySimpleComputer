#include "printConsole.h"

int Terminal::coordinates = 0;
int Terminal::accumulator = 0;
int Terminal::instruction_counter = 0;

Terminal::Terminal()
{
    PC.memoryInit();
    PC.regInit();
    big_cell.fill(myBigChar(myBigChar::BigChar::Zero));
}

void Terminal::printBoxes()
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
void Terminal::printKeys()
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
    std::cout << "q  - quit";
    gotoXY(21, 51);
    std::cout << "F5 - accumulator";
    gotoXY(22, 51);
    std::cout << "F6 - instructionCounter";
}
void Terminal::printFlags()
{
    int flags[5];
    char flagsChar[5] {' '};

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
void Terminal::printMemory()
{
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
                printf("+%.4X", val);
        }
    }
    std::cout << "\n";
}
void Terminal::printAll()
{
    printBoxes();
    printFlags();
    printMemory();
    
    gotoXY(3, 73);
    accumulator < 0 ? printf("-%.4X", -accumulator) : printf("+%.4X", accumulator);

    gotoXY(6, 73);
    printf("+%.4X", instruction_counter);

    gotoXY(24, 14);
}

void Terminal::resetBG()
{
    setCellBG(BLACK);
    setCellBG(RED);
    fflush(stdout);
}

void Terminal::getCellCoords(int&x, int&y)
{
    x = coordinates % 10;
    y = coordinates / 10;
}
int Terminal::setCellBG(int index)
{
    int x, y, val;
    getCellCoords(x, y);

    switch (index)
    {
    case 1:
        setBGColor(BLUE);
        gotoXY(y + 3, (6 + 6 * x) - 3);

        PC.memoryGet(coordinates, val) < 0 ? printf("-%.4X", -val) : printf("+%.4X", val);
        std::cout << "\E[0m";
        return 0;
    case 0:
        setBGColor(LIGHT_BLUE);
        gotoXY(y + 3, (6 + 6 * x) - 3);

        PC.memoryGet(coordinates, val) < 0 ? printf("-%.4X", -val) : printf("+%.4X", val);
        std::cout << "\E[0m";
        return 0;
    default:
        return -1;
    }
}

void Terminal::printBigCell()
{
	int val;

	PC.memoryGet(coordinates, val);
	
	val < 0 ? big_cell[0] = myBigChar(myBigChar::Minus) 
            : big_cell[0] = myBigChar(myBigChar::Plus);
	
	for(int i = 4; i > 0; i--)
	{
		big_cell[i] = myBigChar(val % 16);
		val /= 16; 
	}

    for(int i = 0, j = 3; i < 5; i++, j += 9)
        big_cell[i].print(14, j, Colors::WHITE, Colors::BLACK);
}

void Terminal::moveUp()
{
    int x, y;
    getCellCoords(x, y);

    if(y != 0)
    {
        setCellBG(0);
        y--;
        setCellBG(1);
    }

    coordinates = y * 10 + x;
    reset();
}
void Terminal::moveDown()
{
    int x, y;
    getCellCoords(x, y);

    if(y != 9)
    {
        setCellBG(0);
        y++;
        setCellBG(1);
    }

    coordinates = y * 10 + x;
    reset();
}
void Terminal::moveRight()
{
    int x, y;
    getCellCoords(x, y);

    setCellBG(0);
    if(x != 9)
        x++;
    else if(x == 9 and y != 9)
    {
        x = 0;
        y++;
    }
    setCellBG(1);

    coordinates = y * 10 + x;
    reset();
}
void Terminal::moveLeft()
{
    int x, y;
    getCellCoords(x, y);

    setCellBG(0);
    if(x != 0)
        x--;
    else if(x == 0 and y != 0)
    {
        x = 9;
        y--;
    }
    setCellBG(1);

    coordinates = y * 10 + x;
    reset();
}
void Terminal::keyF5()
{
    int val;
    PC.memoryGet(coordinates, val);
    accumulator = val;
    reset();
    fflush(stdout);
}
void Terminal::keyF6()
{
    int val;
    PC.memoryGet(coordinates, val);
    PC.memorySet(coordinates, val + 1);
    reset();
    fflush(stdout);
}

void Terminal::reset()
{
    clrscr();
    printAll();

    resetBG();
    printBigCell();

    gotoXY(24, 1);
    std::cout << " Input\\Output: ";
    
    gotoXY(25, 1);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 83; j++)
            std::cout << " ";
        std::cout << "\n";
    }

    gotoXY(24, 14);
    fflush(stdout);
}

void Terminal::run()
{
    PC.memoryInit();
    PC.regInit();
    printAll();
    reset();

    while(key != Keys::Quit)
    {
        readkey(key);

        switch (key)
        {
        case Keys::Load:
            PC.memoryLoad("./res/RAM.dat");
            reset();
            break;
        case Keys::Save:
            PC.memorySave("./res/RAM.dat");
            break;
        case Keys::Up:
            moveUp();
            break;
        case Keys::Down:
            moveDown();
            break;
        case Keys::Right:
            moveRight();
            break;
        case Keys::Left:
            moveLeft();
            break;
        case Keys::F5:
            keyF5();
            break;
        case Keys::F6:
            keyF6();
            break;
        case Keys::Reset:
			PC.memoryInit();
			PC.regInit();
			accumulator = 0;
			coordinates = 0;
			instruction_counter = 0;
			reset();
        	break;
        default:
            break;
        }
    }
    fflush(stdout);
    gotoXY(25, 1);
}
