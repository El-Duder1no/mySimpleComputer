#ifndef MY_TERM_H
#define MY_TERM_H

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

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
int gotoXY(int row, int col);
int getScreenSize(int& rows, int& cols);
int setFGColor(Colors color);
int setBGColor(Colors color);
int setDefaultColor();

#endif