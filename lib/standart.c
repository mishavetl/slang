#include <stdio.h>
#include <string.h>
#include "slanglib/standart.h"

int std_len(char *str);

char stdlib_keys[10] = {
    '&',
    '\0'
};

int (*stdlib_funcs[10]) (char*) =
{
    std_len
};


int std_len(char *str)
{
    return strlen(str);
}
