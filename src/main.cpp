#include <iostream>
#include <iomanip>
#include <time.h>
#include "mySimpleComputer.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    int val;
    char* file = new char[8] {'R', 'A', 'M', '.', 'd', 'a', 't', '\0'};

    sc_memoryInit();
    sc_memoryLoad(file);

    for(int i = 0; i < size; i++)
    {
        sc_memoryGet(i, val);
        if(i+1 / 10 == 0)
            cout << "\n";
        cout << setw(4) << val << " "; 
    }
    cout << "\n\n";

    sc_regInit();
    sc_regSet(1, 0);
    sc_regSet(2, 1);
    sc_regSet(3, 1);
    sc_regSet(4, 0);
    sc_regSet(5, 0);

    for(int i = 1; i <= 5; i++)
    {
        sc_regGet(i, val);
        cout << "reg " << i << " " << val << "\n";
    }
    
    return 0;
}
