#include "myBigChars.h"

int printA(const char* str)
{
    std::cout << "\E(0" << str << "\E(B";
    return 0;
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

int printBigChar(int arr[2], int x, int y, Colors fgColor, Colors bgColor)
{
    int row, col;
    getScreenSize(row, col);
    if((x <= 0  or x >= row) or (y <= 0 or y >= col))
        return -1;

    gotoXY(x, y);
    setFGColor(fgColor);
    setBGColor(bgColor);

    char string[8] {};
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int temp = arr[i] >> (j * 8);
            for(int k = 0; k < 8; k++)
            {
                int bit = (temp & (1 << k));
                bit != 0 ? string[k] = 'a' : string[k] = ' ';
            }
            gotoXY(x + (i * 4) + j + 1, y);
            printA(string);
        }
    }
    setDefaultColor();
    gotoXY(x + 10, 0);
    return 0;
}

int setBigCharPos(int* big, int x, int y, int value)
{
    return 0;
}

int getBigCharPos(int& big, int x, int y, int& value)
{
    return 0;
}

int bigCharWrite(int fd, int& big, int need_count, int count)
{
    return 0;
}

int bigCharRead(int fd, int& big, int need_count, int& count)
{
    return 0;
}
