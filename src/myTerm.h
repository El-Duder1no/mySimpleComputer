#ifndef MY_TERM_H
#define MY_TERM_H

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

#define TOP_LEFT_CORNER      "l"
#define TOP_RIGHT_CORNER     "k"
#define BOT_LEFT_CORNER      "m"
#define BOT_RIGHT_CORNER     "j"
#define HORIZONTAL_LINE      "q"
#define VERTICAL_LINE        "x"

enum Colors
{
   BLACK,
   RED,
   GREEN,
   YELLOW,
   BLUE,
   PURPLE,
   LIGHT_BLUE,
   WHITE,
};

int clrscr();
int printA(const char* str);
int gotoXY(int row, int col);
int printBox(int x, int y, int height, int width);
int getScreenSize(int& rows, int& cols);
int setFGColor(Colors color);
int setBGColor(Colors color);
int setDefaultColor();

#endif