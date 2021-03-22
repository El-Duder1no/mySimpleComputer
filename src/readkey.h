#ifndef MY_READ_KEY_H
#define MY_READ_KEY_H

#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include "myTerm.h"

enum Keys
{
    Up = 10,
    Down,
    Left,
    Right,
    Load,
    Save,
    Run,
    Step,
    Reset,
    F5,
    F6,
    None
};

int readkey(Keys& key);
int mytermsave();
int mytermrestore();
int mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

#endif