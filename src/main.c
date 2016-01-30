#include <stdio.h>
#include <stdlib.h>
#include "slang/console.h"
// #include <slang/parser.h>

extern char *filepath;

int main(int argc, char *argv[])
{
    if (parse_args(argc, argv) != 0) {
        return 1;
    }

    FILE *fp = fopen(filepath, "r");
    char buf[1000];

    while (fgets(buf, 1000, fp) != NULL) {
		printf("%s", buf);
    }

    fclose(fp);

    return 0;
}
