#include <stdio.h>
#include <stdlib.h>
#include "slang/console.h"
#include "slang/formatutils.h"
#include "slang/parser.h"

extern char *filepath;
extern char *args[];
extern int argsc;

long fsize;

int main(int argc, char *argv[])
{
    if (parse_args(argc, argv) != 0) {
        return 1;
    }

    FILE *f = fopen(filepath, "rb");

    if (f == NULL) {
        errorp("file not found or is not accesible");

        return 1;
    }

    fseek(f, 0, SEEK_END);
    fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *content = malloc(fsize + 1);

    fread(content, fsize, 1, f);

    fclose(f);

    content[fsize] = '\0';

    // printf("%s", content);

    if (parse(content, fsize, argsc, args) != 0) {
        free(content);
        puts("\n");
        errorp("bad");
        return 1;
    }

    free(content);

    puts("\n");
    smallsuccessp("ok");

    return 0;
}
