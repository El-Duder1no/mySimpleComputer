#ifndef MY_READ_KEY_H
#define MY_READ_KEY_H

#include <cstring>
#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include "myTerm.h"

extern termios options;

enum Keys
{
    Up = 10,
    Down,
    Right,
    Left,
    F5,
    F6,
    Load,
    Save,
    Run,
    Step,
    Reset,
    Quit,
    None
};

int readkey(Keys& key);
int mytermsave();
int mytermrestore();
int mytermregime(bool regime, bool echo, bool sigint, int vtime, int vmin);

#endif
