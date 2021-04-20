#include "readkey.h"

int readkey(Keys& key)
{
    mytermregime(1, 0, 1, 1, 1);

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
	termios options;
    if(tcgetattr(STDIN_FILENO, &options) != 0)
        return -1;

    return 0;
}

int mytermrestore()
{
	termios options;
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &options) != 0)
        return -1;

    return 0;
}

int mytermregime(int regime, int vtime, int vmin, int echo, int sigint)
{
	termios options;
    termios new_options;

    mytermsave();
    new_options = options;

    if(regime == 0)
        new_options.c_lflag |= ICANON;
    else if(regime == 1)
    {
        new_options.c_lflag &= ~ICANON;

        if(echo == 1)
            new_options.c_lflag |= ECHO;
        else if(echo == 0)
            new_options.c_lflag &= ~ECHO;

        if(sigint == 1)
            new_options.c_lflag |= ISIG;
        else if(sigint == 0)
            new_options.c_lflag &= ~ISIG;

        new_options.c_cc[VTIME] = vtime;
        new_options.c_cc[VMIN] = vmin;
    }

    if(tcsetattr(0, TCSANOW, &new_options) != 0)
        return -1;
    
    return 0;
}
