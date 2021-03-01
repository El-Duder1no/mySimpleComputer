#include "myTerm.h"

int clrscr()
{
    std::cout << "\E[H\E[2J";
    return 0;
}

int gotoXY(int row, int col)
{
    int x, y;
    getScreenSize(x, y);
    if((row >= 0 and row <= x) and (col >= 0 and col <= y))
    {
        std::cout << "\E[" << row << ";" << col << "H";
        return 0;
    }
    else
        return -1;
}

int getScreenSize(int& rows, int& cols)
{
    struct winsize ws;
    if(!ioctl(1, TIOCGWINSZ, &ws))
    {
        rows = ws.ws_row;
        cols = ws.ws_col;
        return 0;
    }
    else
        return -1;
}

int setFGColor(Colors color)
{
    if(color >= BLACK and color <= WHITE)
    {
        std::cout << "\E[3" << color << "m";
        return 0;
    }
    else
        return -1;
}

int setBGColor(Colors color)
{
    if(color >= BLACK and color <= WHITE)
    {
        std::cout << "\E[4" << color << "m";
        return 0;
    }
    else
        return -1;
}