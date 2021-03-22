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
        
    myComputer PC;
    PC.regSet(myComputer::OPERATION_OVERFLOW, 1);
    PC.regSet(myComputer::DIVISION_BY_ZERO, 0);
    PC.regSet(myComputer::OUT_OF_BOUNDS, 1);
    PC.regSet(myComputer::CLOCK_PULSE_IGNORE, 0);
    PC.regSet(myComputer::INVALID_COMMAND, 1);    
    std::array<myBigChar::BigChar, 4> arr{myBigChar::Zero};

    printAll(myBigChar::Plus, arr);
    
    return 0;
}
