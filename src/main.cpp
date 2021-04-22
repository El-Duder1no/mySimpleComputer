#include "handler.h"

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    srand(time(nullptr));

    Handler term;
    term.run();

    return 0;
}
