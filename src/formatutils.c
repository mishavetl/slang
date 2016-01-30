#include <stdio.h>
#include "slang/formatutils.h"

// ==================================================
// Format utils
// ==================================================

void errorp(char *mesg)
{
    printf("\e[1;31m[e] %s\e[0m\n", mesg);
}


void infop(char *mesg)
{
    printf("\e[0;34m[i] %s\e[0m\n", mesg);
}

void smallsuccessp(char *mesg)
{
    printf("\e[0;32m[s] %s\e[0m\n", mesg);
}

void successp(char *mesg)
{
    printf("\e[1;32m[s] %s\e[0m\n", mesg);
}
