#include <stdio.h>

// ==================================================
// Format utils
// ==================================================

void errorp(char *mesg)
{
    printf("\e[1;31m[e] %s\e[0m\n", mesg);
}


void infop(char *mesg)
{
    printf("\e[1;34m[i] %s\e[0m\n", mesg);
}



void help()
{
    puts("SLang (String Language) \
        slang filepath [-h] \
        -h, --help -- show help message \
        filepath   -- path to the script file"
    );
}


char *filepath;

int parse_args(int argc, char *argv[])
{
    if (argc < 2) {
        errorp("you need one more argument");
        infop("try --help, -h");

        return 1;

    } else if (argc > 2) {
        errorp("too many arguments");
        infop("try --help, -h");

        return 1;

    }

    if (argv[1] == "-h" || argv[1] == "--help") {
        help();

        return 1;
    }

    filepath = argv[1];

    return 0;
}
