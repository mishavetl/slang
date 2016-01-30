#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "slang/parser.h"
#include "slang/formatutils.h"
#include "../lib/slanglib/io.h"
#include "slang/utils.h"
#include "../lib/slanglib/standart.h"

extern char iolib_keys[10];
extern int (*iolib_funcs[10]) (char*);

extern char stdlib_keys[10];
extern int (*stdlib_funcs[10]) (char*);

int intres = 0;

int parse(char *content, long fsize, int argsc, char *args[])
{
    int i, j;
    char *res = (char *) malloc(fsize * sizeof(char));
    char *str = malloc(fsize * sizeof(char));
    bool _func = false;
    bool _error = false;
    char fname;

    if (res == NULL) {
        return 1;
    } else if (str == NULL) {
        return 1;
    }

    for (i = 0; i < fsize; i++) {
        // printf("content[%d]: %c\n", i, content[i]);
        if (_error) {
            break;
        }

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
            } else if (fname == '"') {
                j = 0;
                while (i < fsize) {
                    if (content[i] == '"') {
                        break;
                    } else if (i == fsize - 1) {
                        sprintf(str, "unexpected eof on %d while proccessing '\"'", i);
                        errorp(str);
                        _error = true;
                        break;
                    }

                    res[j++] = content[i];
                    i++;
                }

                res[j] = '\0';
            } else if (fname == '$') {
                if (((int) content[i]) - 49 >= argsc) {
                    sprintf(str, "you need at least %d argument(s) to start this program", ((int) content[i]) - 48);
                    errorp(str);
                    _error = true;
                    break;
                }

                strcpy(res, args[((int) content[i]) - 49]);
                // printf("args: %s\n", args[0]);
            } else if (fname == '>') {
                // puts("here");
                j = find(iolib_keys, content[i]);

                if (j != -1) {
                    intres = iolib_funcs[j](res);
                } else {
                    sprintf(str, "'>' has no member '%c' on %d", content[i], i);
                    errorp(str);
                }
            } else if (fname == '/') {
                j = find(stdlib_keys, content[i]);

                if (j != -1) {
                    intres = stdlib_funcs[j](res);
                } else {
                    sprintf(str, "'/' has no member '%c' on %d", content[i], i);
                    errorp(str);
                }
            }

            _func = !_func;
        }
    }

    free(str);
    free(res);

    if (_error) return 1;

    return 0;
}
