#include "myBigChars.h"

myBigChar::myBigChar() : symbol(char_collection[0]) {}
myBigChar::myBigChar(myBigChar::BigChar symbol)
{
    switch(symbol)
    {
    case BigChar::Zero:
        this->symbol = char_collection[0];
        break;
    case BigChar::One:
        this->symbol = char_collection[1];
        break;
    case BigChar::Two:
        this->symbol = char_collection[2];
        break;
    case BigChar::Three:
        this->symbol = char_collection[3];
        break;
    case BigChar::Four:
        this->symbol = char_collection[4];
        break;
    case BigChar::Five:
        this->symbol = char_collection[5];
        break;
    case BigChar::Six:
        this->symbol = char_collection[6];
        break;
    case BigChar::Seven:
        this->symbol = char_collection[7];
        break;
    case BigChar::Eight:
        this->symbol = char_collection[8];
        break;  
    case BigChar::Nine:
        this->symbol = char_collection[9];
        break;
    case BigChar::Plus:
        this->symbol = char_collection[10];
        break;
    case BigChar::Minus:
        this->symbol = char_collection[11];
        break; 
    }
}

int myBigChar::printA(const char* str)
{
    std::cout << "\E(0" << str << "\E(B";
    return 0;
}

int myBigChar::printBox(int x, int y, int height, int width)
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

int myBigChar::print(int x, int y, Colors fgColor, Colors bgColor)
{
    int row, col;
    getScreenSize(row, col);
    if((x <= 0  or x >= row) or (y <= 0 or y >= col))
        return -1;

    gotoXY(x, y);
    setFGColor(fgColor);
    setBGColor(bgColor);

    char string[8] {0};
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int buf = (symbol[i] >> (j * 8)) & 0xFF;

            for(int k = 0; k < 8; k++)
            {
                int bit = (buf & (1 << k)) >> k;
                bit != 0 ? string[k] = BLOCK[0] : string[k] = ' ';
            }
            gotoXY(x + (i * 4) + j + 1, y);
            printA(string);
        }
    }
    setDefaultColor();
    gotoXY(18, 0);
    return 0;
}

int myBigChar::setPos(int* big, int x, int y, int value)
{
    if(x < 0 or x > 7 or y < 0 or y > 7)
        return -1;
    if(value == 1)
        big[x / 4] |= 1 << ((x % 4) * 8 + y);
    else if(value == 0)
        big[x / 4] &= ~(1 << ((x % 4) * 8 + y));
    
    return 0;
}

int myBigChar::getPos(int* big, int x, int y, int& value)
{
    if(x < 0 or x > 7 or y < 0 or y > 7)
        return -1;

    value = (big[x / 4] >> ((x % 4) * 8 + y)) & 0x1;
    
    return 0;
}

int myBigChar::writeBC(int fd, int* big, int need_count, int count)
{
    ::write(fd, big, count * sizeof(int) * 2);
    close(fd);
    return 0;
}

int myBigChar::readBC(int fd, int* big, int need_count, int& count)
{
    read(fd, big, need_count * sizeof(int) * 2);
    close(fd);
    return 0;
}
