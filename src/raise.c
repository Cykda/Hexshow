#include <stdio.h>
#include <stdlib.h>
#include "raise.h"




void raise_error(char* error, int state)
{
    fprintf(stderr, "%s", error);
    exit(state);
}