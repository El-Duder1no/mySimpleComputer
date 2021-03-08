#ifndef MY_BIGCHARS_H
#define MY_BIGCHARS_H

#include "myTerm.h"
#include <array>
#include <unistd.h>

#define TOP_LEFT_CORNER      "l"
#define TOP_RIGHT_CORNER     "k"
#define BOT_LEFT_CORNER      "m"
#define BOT_RIGHT_CORNER     "j"
#define HORIZONTAL_LINE      "q"
#define VERTICAL_LINE        "x"

#define BLOCK                'a'

typedef std::array<unsigned, 2> BC_ARRAY;

class myBigChar
{
protected: 
    const std::array<BC_ARRAY, 12> char_collection
    {
        3'890'741'118,  2'130'700'263,  // 0
        943'602'744,    943'208'504,    // 1
        1'894'252'414,  4'294'903'580,  // 2
        2'145'451'903,  2'147'475'680,  // 3
        4'286'019'447,  1'886'417'151,  // 4
        2'131'230'719,  2'130'698'495,  // 5
        2'131'230'590,  2'130'700'287,  // 6
        1'893'793'791,  471'604'280,    // 7
        2'129'133'438,  2'129'127'399,  // 8
        4'293'394'302,  2'130'698'494,  // 9
        2'115'508'224,  1'579'134,      // +
        2'113'929'216,  126             // -
    }; 
    BC_ARRAY symbol;

public:
    enum BigChar
    {
        Zero, One,  Two,    Three,  Four,
        Five, Six,  Seven,  Eight,  Nine,
        Plus, Minus 
    };

    myBigChar(BigChar symbol);

    int printA(const char* str);
    int printBox(int x, int y, int height, int width);
    int print(int x, int y, Colors fgColor, Colors bgColor);
    int setPos(int* big, int x, int y, int value);
    int getPos(int* big, int x, int y, int& value);
    int writeBC(int fd, int* big, int need_count, int count);
    int readBC(int fd, int* big, int need_count, int& count);

};

// int printA(const char* str);
// int printBox(int x, int y, int height, int width);
// int printBigChar(long int arr[2], int x, int y, Colors fgColor, Colors bgColor);
// int setBigCharPos(int* big, int x, int y, int value);
// int getBigCharPos(int& big, int x, int y, int& value);
// int bigCharWrite(int fd, int& big, int need_count, int count);
// int bigCharRead(int fd, int& big, int need_count, int& count);

#endif