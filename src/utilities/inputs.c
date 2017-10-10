#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "includes/inputs.h"


char getch(void)
{
        struct termios oldattr, newattr;
        short ch;
        tcgetattr(1, &oldattr);
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(1, TCSANOW, &newattr);
        ch = getchar();
        tcsetattr(1, TCSANOW, &oldattr);
        return ch;
}


char kbhit()
{
        struct termios oldt, newt;
        char out;
        char * ch = (char *) malloc(KBHIT_BUFFER);
        short oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        if(!(fscanf(stdin,"%s", ch))) {
                fprintf(stderr, "error -> %d\n", EIO);
                exit(1);
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        out = ch[0];

        free(ch);

        return out;
}
