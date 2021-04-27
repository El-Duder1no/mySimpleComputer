#ifndef PRINT_CONSOLE_H
#define PRINT_CONSOLE_H

#include <iostream>
#include <iomanip>
#include <array>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "readkey.h"

class Handler
{
protected:
    myComputer PC;
    Keys key;
    static int coordinates;
    static int accumulator;
    static int instruction_counter;
    std::array<myBigChar, 5> big_cell;

    void printBoxes();
    void printKeys();
    void printFlags();
    void printMemory();
    void printAll();

    void resetBG();

    void getCellCoords(int&x, int&y);
    int setCellBG();
    
    void printBigCell();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void keyF5();
    void keyF6();

    void reset();

    void setTimer(long interval);
    void resetSignal(int signal);
    void signalHandler(int signal);

public:
    Handler();

    void run();
};

#endif
