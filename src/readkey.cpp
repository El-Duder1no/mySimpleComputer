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
    else
        key = Keys::None;

    mytermrestore();
    return 0;
}

int mytermsave()
{
    termios terminal;
    FILE* term;

    if(tcgetattr(0, &terminal) != 0)
        return -1;
    
    if((term = fopen("term", "wb")) == NULL)
        return -1;
    
    fwrite(&terminal, sizeof(terminal), 1, term);
    fclose(term);

    return 0;
}

int mytermrestore()
{
    termios terminal;
    FILE* term;
	
	if((term = fopen("term", "wb")) == NULL)
		return -1;
	
    if(fread(&terminal, sizeof(terminal), 1, term) > 0)
    {
        if(tcsetattr(0, TCSAFLUSH, &terminal) != 0)
            return -1;
        else
            fclose(term);
    }

    return 0;
}

int mytermregime(int regime, int vtime, int vmin, int echo, int sigint)
{
    termios options;

    if(tcgetattr(0, &options) != 0)
        return -1;
    
    if(regime == 1)
        options.c_lflag |= ICANON;
    else if(regime == 0)
    {
        options.c_lflag &= ~ICANON;

        options.c_cc[VTIME] = vtime;
        options.c_cc[VMIN] = vmin;

        if(echo == 1)
            options.c_lflag |= ECHO;
        else if(echo == 0)
            options.c_lflag &= ~ECHO;
        
        if(sigint == 1)
            options.c_lflag |= ISIG;
        else if(sigint == 0)
            options.c_lflag &= ~ISIG;
    }

    if(tcsetattr(0, TCSANOW, &options) != 0)
        return -1;
    
    return 0;
}
