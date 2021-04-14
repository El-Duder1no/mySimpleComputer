#ifndef MY_BIGCHARS_H
#define MY_BIGCHARS_H

#include "myTerm.h"

#include <array>
#include <map>
#include <unistd.h>

#define BLOCK   "a"

typedef std::array<unsigned, 2> BC_ARRAY;

class myBigChar
{
public:
    enum BigChar
    {
        Zero, One,  Two,    Three,  Four,
        Five, Six,  Seven,  Eight,  Nine,
        A,    B,    C,      D,      E, 
        F,    Plus, Minus
    };
    myBigChar();
    myBigChar(int symbol);

    void init(int symbol);
    int print(int x, int y, Colors fgColor, Colors bgColor);
    int setPos(int* big, int x, int y, int value);
    int getPos(int* big, int x, int y, int& value);
    int writeBC(int fd, int* big, int need_count, int count);
    int readBC(int fd, int* big, int need_count, int& count);

protected:
    static std::map<int, BC_ARRAY> char_collection;
    BC_ARRAY symbol;
};

#endif
