#include "slang/utils.h"

int find(char keys[], char q)
{
    int i = 0;

    while (keys[i] != '\0') {
        if (keys[i] == q) {
            return i;
        }
        i++;
    }

    return -1;
}
