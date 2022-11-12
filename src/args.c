#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "args.h"


void init(arguments* argument, int argc, char** argv)
{
    argument->argc = argc;
    argument->argv = argv;
}



bool does_exist(arguments argument, char* arg)
{
    for(int i = 1; i < argument.argc; ++i)
    {
        if(strcmp(argument.argv[i], arg) == 0)
        {
            return true;
        }
    }
    return false;
}



bool check_parameter(arguments argument, int position, char* error_msg)
{
    if(position + 1 > argument.argc - 1)
    {
        printf("%s\n", error_msg);
        return false;
    }
    else
    {
        return true;
    }
}


char* get_parameter(arguments argument, int position)
{
    return argument.argv[position + 1];
}



int get_parameter_position(arguments argument, char* arg)
{
    for(int i = 1; i < argument.argc; ++i)
    {
        if(strcmp(argument.argv[i], arg) == 0)
        {
            return i - 1;
        }
    }
    return -1;
}