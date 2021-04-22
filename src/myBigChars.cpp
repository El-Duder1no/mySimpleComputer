#include "myBigChars.h"

std::map<int, BC_ARRAY> myBigChar::char_collection =
{
    {0,     BC_ARRAY {3'890'741'118,  2'130'700'263}},  // 0
    {1,     BC_ARRAY {943'602'744,    943'208'504}},    // 1
    {2,     BC_ARRAY {1'894'252'414,  4'294'903'580}},  // 2
    {3,     BC_ARRAY {2'145'451'903,  2'147'475'680}},  // 3
    {4,     BC_ARRAY {4'286'019'447,  1'886'417'151}},  // 4
    {5,     BC_ARRAY {2'131'230'719,  2'130'698'495}},  // 5
    {6,     BC_ARRAY {2'131'230'590,  2'130'700'287}},  // 6
    {7,     BC_ARRAY {1'893'793'791,  471'604'280}},    // 7
    {8,     BC_ARRAY {2'129'133'438,  2'129'127'399}},  // 8
    {9,     BC_ARRAY {4'293'394'302,  2'130'698'494}},  // 9
    {10,    BC_ARRAY {3'890'741'118,  3'890'741'247}},  // A
    {11,    BC_ARRAY {2'145'910'655,  2'145'904'615}},  // B
    {12,    BC_ARRAY {1'32'644'734,   2'130'700'039}},  // C
    {13,    BC_ARRAY {3'890'741'119,  2'147'477'479}},  // D
    {14,    BC_ARRAY {1'057'488'895,  4'294'903'615}},  // E
    {15,    BC_ARRAY {1'057'488'895,  117'901'119}},    // F
    {16,    BC_ARRAY {2'115'508'224,  1'579'134}},      // +
    {17,    BC_ARRAY {2'113'929'216,  126}},            // -
};

myBigChar::myBigChar() : symbol(char_collection[Zero]) {}
myBigChar::myBigChar(int symbol)
{
    init(symbol);
}

void myBigChar::init(int symbol)
{
    if(char_collection.count(symbol) == 1)
        this->symbol = char_collection[symbol];
    else
        this->symbol = char_collection[Zero];
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
    write(fd, big, count * sizeof(int) * 2);
    close(fd);
    return 0;
}

int myBigChar::readBC(int fd, int* big, int need_count, int& count)
{
    read(fd, big, need_count * sizeof(int) * 2);
    close(fd);
    return 0;
}
