#include "handler.h"

int Handler::coordinates = 0;
int Handler::accumulator = 0;
int Handler::instruction_counter = 0;

Handler::Handler()
{
    PC.memoryInit();
    PC.regInit();
    big_cell.fill(myBigChar(0));
}

void Handler::printBoxes()
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
void Handler::printKeys()
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
void Handler::printFlags()
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
void Handler::printMemory()
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
void Handler::printAll()
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

void Handler::resetBG()
{
    setCellBG();
    fflush(stdout);
}

void Handler::getCellCoords(int&x, int&y)
{
    x = coordinates % 10;
    y = coordinates / 10;
}
int Handler::setCellBG()
{
    int x, y, val;
    getCellCoords(x, y);

    setBGColor(LIGHT_BLUE);
    gotoXY(y + 3, (6 + 6 * x) - 3);

    PC.memoryGet(coordinates, val) < 0 ? printf("-%.4X", -val) : printf("+%.4X", val);
    std::cout << "\E[0m";
    return 0;
}

void Handler::printBigCell()
{
	int val;
	PC.memoryGet(coordinates, val);

	val >= 0 ? big_cell[4] = myBigChar(myBigChar::Plus)
             : big_cell[4] = myBigChar(myBigChar::Minus);
	
	for(int i = 0; i < 4; i++)
	{
		big_cell[i] = myBigChar(val % 16);
		val /= 16;
	}

    big_cell[4].print(14, 3,  Colors::WHITE, Colors::BLACK);
    big_cell[3].print(14, 12, Colors::WHITE, Colors::BLACK);
    big_cell[2].print(14, 21, Colors::WHITE, Colors::BLACK);
    big_cell[1].print(14, 30, Colors::WHITE, Colors::BLACK);
    big_cell[0].print(14, 39, Colors::WHITE, Colors::BLACK);
}

void Handler::moveUp()
{
    int x, y;
    getCellCoords(x, y);

    if(y != 0)
    {
        setCellBG();
        y--;
    }

    coordinates = y * 10 + x;
    reset();
}
void Handler::moveDown()
{
    int x, y;
    getCellCoords(x, y);

    if(y != 9)
    {
        setCellBG();
        y++;
    }

    coordinates = y * 10 + x;
    reset();
}
void Handler::moveRight()
{
    int x, y;
    getCellCoords(x, y);

    setCellBG();
    if(x != 9)
        x++;
    else if(x == 9 and y != 9)
    {
        x = 0;
        y++;
    }

    coordinates = y * 10 + x;
    reset();
}
void Handler::moveLeft()
{
    int x, y;
    getCellCoords(x, y);

    setCellBG();
    if(x != 0)
        x--;
    else if(x == 0 and y != 0)
    {
        x = 9;
        y--;
    }

    coordinates = y * 10 + x;
    reset();
}
void Handler::keyF5()
{
    int val;
    PC.memoryGet(coordinates, val);
    accumulator = val;
    reset();
    fflush(stdout);
}
void Handler::keyF6()
{
    int val;
    PC.memoryGet(coordinates, val);
    PC.memorySet(coordinates, val + 1);
    reset();
    fflush(stdout);
}

void Handler::reset()
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

    gotoXY(24, 15);
    fflush(stdout);
}

void Handler::setTimer(long interval)
{
	itimerval nval, oval;
	
    nval.it_interval.tv_sec = interval;
    nval.it_interval.tv_usec = 0;
    nval.it_value.tv_sec = 1;
    nval.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &nval, &oval);    
}

void Handler::resetSignal(int signal)
{
    accumulator = 0;
    instruction_counter = 0;
    PC.regInit();
    PC.memoryInit();
    reset();
}

void Handler::signalHandler(int signal)
{
    int value;
    PC.regGet(myComputer::CLOCK_PULSE_IGNORE, value);
    if(value == 0)
    {
        instruction_counter++;
        reset();
    }
}

void Handler::run()
{
    PC.memoryInit();
    PC.regInit();
    printAll();

    PC.regSet(myComputer::CLOCK_PULSE_IGNORE, 0);
        
    obj = this;
    signal(SIGUSR1, signal_handler);
    signal(SIGALRM, signal_handler);

    while(key != Keys::Quit)
    {
	    reset();
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
            raise(SIGUSR1);
			reset();
        	break;
        default:
            break;
        }
    }
    gotoXY(33, 1);
    mytermregime(1, 0, 0, 0, 1);
}
