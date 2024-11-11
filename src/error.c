#include"../inc/header.h"


int file_error(int argc, char *argv[])
{
    (void)argv;
    if(argc != 2)
    {
        print_str_error("usage: ./pathfinder [filename]\n");
        return 1;
    }
    return 0;
}

