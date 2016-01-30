#include "slang/utils.h"

int find(char key[], char q)
{
    int i;

    while (key[i] != '\0') {
        if (key[i] == q) {
            return i;
        }
        i++;
    }

    return -1;
}
