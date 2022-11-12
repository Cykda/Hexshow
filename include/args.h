#ifndef ARGS_H
#define ARGS_H


#include <stdbool.h>
typedef struct arguments arguments;
struct arguments
{
    char** argv;
    int argc;
};


void init(arguments* argument, int argc, char** argv);
bool does_exist(arguments argument, char* arg);
bool check_parameter(arguments argument, int position, char* error_msg);
char* get_parameter(arguments argument, int position);
int get_parameter_position(arguments argument, char* arg);
#endif /*ARGS_H*/