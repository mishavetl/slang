#include <stdio.h>
#include "slanglib/io.h"

int io_out(char *str)
{
    printf("%s", str);

    return 0;
}


char iolib_keys[10] = {
    '>',
    '\0'
};

int (*iolib_funcs[10]) (char*) =
{
    io_out
};
