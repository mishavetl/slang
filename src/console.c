#include <stdio.h>
#include <string.h>
#include "slang/console.h"
#include "slang/formatutils.h"

void help()
{
    puts("Copyright (C) 2016 Michael Vietluzhskih \
    \nSLang (String Programming Language) \n \
    slang filepath [-h] \n\t \
    -h, --help -- show help message \n\t \
    filepath   -- path to the script file"
    );
}


char *filepath;
char *args[3];

int argsc = 0;

void set_args(int argc, char *argv[])
{
    for (; argsc < argc - 2; argsc++) {
        args[argsc] = argv[argsc + 2];
    }
}

int parse_args(int argc, char *argv[])
{
    if (argc < 2) {
        errorp("you need one more argument");
        infop("try --help, -h");

        return 1;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        help();

        return 1;
    }

    filepath = argv[1];

    set_args(argc, argv);

    return 0;
}
