#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "slang/parser.h"
#include "slang/formatutils.h"
#include "../lib/slanglib/io.h"

int parse(char *content, long fsize, int argsc, char *args[])
{
    int i;
    char *res;
    bool _func = false;
    char fname;

    for (i = 0; i < fsize; i++) {
        // printf("content[%d]: %c\n", i, content[i]);
        if (!_func) {
            if (content[i] == ' ' || content[i] == '\n') {
                continue;
            }
            _func = true;
            fname = content[i];
            // printf("fname: %c\n", fname);
        } else {
            if (fname == '_' && content[i] == '_') {
                while (i < fsize) {
                    // printf("content[i + 1]: %c\n", content[i + 1]);
                    if (content[i] == '_' && content[i + 1] == '_') {
                        break;
                    }
                    i++;
                }
                i++;
            } else if (fname == '$') {
                res = args[((int) content[i]) - 49];
                // printf("args: %s\n", args[0]);
            } else if (fname == '>' && content[i] == '>') {
                // puts("here");
                io_out(res);
            }

            _func = !_func;
        }
    }

    return 0;
}
