#include "printConsole.h"

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    srand(time(nullptr));
        
    Terminal term;
    term.run();

    return 0;
}
