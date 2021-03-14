#include "myTerm.h"

int clrscr()
{
    std::cout << "\E[H\E[2J";
    return 0;
}

int printA(const char* str)
{
    std::cout << "\E(0" << str << "\E(B";
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

int printBox(int x, int y, int height, int width)
{
    int row, col;
    getScreenSize(row, col); 
    if((x <= 0  or x >= row) or (y <= 0 or y >= col))
        return -1;

    gotoXY(x + height, y);
    printA(BOT_LEFT_CORNER);
    gotoXY(x, y);
    printA(TOP_LEFT_CORNER);
    gotoXY(x + height, y + width);
    printA(BOT_RIGHT_CORNER);
    gotoXY(x, y + width);
    printA(TOP_RIGHT_CORNER);

    for(int i = x + 1; i < x + height; i++)
    {
        gotoXY(i, y);
        printA(VERTICAL_LINE);
        gotoXY(i, y + width);
        printA(VERTICAL_LINE);
    }

    for(int i = y + 1; i < y + width; i++)
    {
        gotoXY(x, i);
        printA(HORIZONTAL_LINE);
        gotoXY(x + height, i);
        printA(HORIZONTAL_LINE);
    }
    std::cout << "\n";
    
    return 0;
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

int setDefaultColor()
{
	std::cout << "\E[0m";
	return 0;
}
