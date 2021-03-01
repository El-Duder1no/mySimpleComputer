#ifndef MY_BIGCHARS_H
#define MY_BIGCHARS_H

#include "myTerm.h"

#define TOP_LEFT_CORNER     "l"
#define TOP_RIGHT_CORNER    "k"
#define BOT_LEFT_CORNER     "m"
#define BOT_RIGHT_CORNER    "j"
#define HORIZONTAL_LINE     "q"
#define VERTICAL_LINE       "x"
 
int printA(const char* str);
int printBox(int x, int y, int height, int width);
int printBigChar(int arr[2], int x, int y, Colors fgColor, Colors bgColor);
int setBigCharPos(int* big, int x, int y, int value);
int getBigCharPos(int& big, int x, int y, int& value);
int bigCharWrite(int fd, int& big, int need_count, int count);
int bigCharRead(int fd, int& big, int need_count, int& count);

#endif