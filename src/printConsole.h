#ifndef PRINT_CONSOLE_H
#define PRINT_CONSOLE_H

#include <iostream>
#include <iomanip>
#include <array>
#include <sys/ioctl.h>
#include <unistd.h>

#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "readkey.h"

class Terminal
{
protected:
    myComputer PC;
    Keys key;
    static int coordinates;
    static int accumulator;
    static int instruction_counter;
    static std::array<myBigChar, 5> big_cell;

    void printBoxes();
    void printKeys();
    void printFlags();
    void printMemory();
    void printAll();

    void resetBG();

    void getCellCoords(int&x, int&y);
    int setCellBG(int index);
    
    void printBigCell();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void keyF5();
    void keyF6();

    void reset();

public:
    Terminal();

    void run();
};

#endif
