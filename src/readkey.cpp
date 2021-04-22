#include "readkey.h"

termios options;

int readkey(Keys& key)
{
    mytermregime(1, 1, 1, 0, 1);

    char buffer[8] {};

    read(STDIN_FILENO, buffer, 8);
    
    if(strcmp(buffer, "\E[A") == 0)
        key = Keys::Up;
    else if(strcmp(buffer, "\E[B") == 0)
        key = Keys::Down;
    else if(strcmp(buffer, "\E[C") == 0)
        key = Keys::Right;
    else if(strcmp(buffer, "\E[D") == 0)
        key = Keys::Left;
    else if(strcmp(buffer, "\E[15~") == 0)
        key = Keys::F5;
    else if(strcmp(buffer, "\E[17~") == 0)
        key = Keys::F6;
    else if(buffer[0] == 'l')
        key = Keys::Load;
    else if(buffer[0] == 's')
        key = Keys::Save;
    else if(buffer[0] == 'r')
        key = Keys::Run;
    else if(buffer[0] == 't')
        key = Keys::Step;
    else if(buffer[0] == 'i')
        key = Keys::Reset;
    else if(buffer[0] == 'q')
        key = Keys::Quit;
    else
        key = Keys::None;

    mytermrestore();
    return 0;
}

int mytermsave()
{
    if(tcgetattr(0, &options) != 0)
        return -1;

    return 0;
}

int mytermrestore()
{
    if(tcsetattr(0, TCSANOW, &options) != 0)
        return -1;

    return 0;
}

int mytermregime(bool regime, bool echo, bool sigint, int vtime, int vmin)
{
    termios new_options;

    mytermsave();
    new_options = options;

    if(!regime)
        new_options.c_lflag |= ICANON;
    else
    {
        new_options.c_lflag &= ~ICANON;
        echo == true ? new_options.c_lflag &= ~ECHO : new_options.c_lflag |= ECHO;
        sigint == true ? new_options.c_lflag &= ~ISIG : new_options.c_lflag |= ISIG;

        new_options.c_cc[VTIME] = vtime;
        new_options.c_cc[VMIN] = vmin;
    }

    if(tcsetattr(0, TCSANOW, &new_options) != 0)
        return -1;
    
    return 0;
}
