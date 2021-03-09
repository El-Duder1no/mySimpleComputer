#include "printConsole.h"

void printBoxes()
{
    myBigChar box;
    box.printBox(1, 1, 12, 61);
    box.printBox(1, 62, 3, 22);
    box.printBox(4, 62, 3, 22);
    box.printBox(7, 62, 3, 22);
    box.printBox(10, 62, 3, 22);
    
    box.printBox(13, 1, 10, 46);
    box.printBox(13, 47, 10, 37);
}
