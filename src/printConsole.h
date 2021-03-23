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

void printBoxes();
void printKeys();
void printFlags();
void printMemory();
void printBigChars(myBigChar::BigChar sign, std::array<myBigChar::BigChar, 4> chars);
void printAll(myBigChar::BigChar sign, std::array<myBigChar::BigChar, 4> chars);

void runConsole(myBigChar::BigChar sign, std::array<myBigChar::BigChar, 4> chars);

#endif
