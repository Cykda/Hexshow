#include <stdio.h>
#include "actions.h"


void print_file_content(char* path)
{
    FILE* file = fopen(path, "rb");
    char ch;
    
    
    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
        
    }
   
    
    fclose(file);
}


