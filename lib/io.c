#include <stdio.h>
#include "slanglib/io.h"

extern intres;

int io_out(char *str);
int io_newline(char *str);
int io_out_number(char *str);

char iolib_keys[10] = {
    '>',
    'n',
    '#',
    '\0'
};

int (*iolib_funcs[10]) (char*) =
{
    io_out,
    io_newline,
    io_out_number
};


int io_out(char *str)
{
    printf("%s", str);

    return 0;
}

int io_out_number(char *str)
{
    printf("%d", intres);

    return 0;
}

int io_newline(char *str)
{
    puts("");

    return 0;
}
