#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "actions.h"
#include "raise.h"
#include "utils.h"

#define MAX_ROW 20
#define HELP_PATH "./assets/help/help.txt"

int main(int argc, char** argv)
{
    char ch;
    int CurrentRow = 0;
    
    arguments args;
    
    init(&args, argc, argv);


    if(does_exist(args, "--help"))
    {
        print_file_content(HELP_PATH);
        return 0;
    }
    
    
    
    // checking parameters existance
    if(!check_parameter(args, 0, "Error: No file specified"))
    {
        print_file_content(HELP_PATH);
        return 0;
    }
    
    
    char* file_path = get_parameter(args, 0);
    
    // initiating files
    FILE* file = fopen(file_path, "rb");
    FILE* outputFile = NULL;
    
    // check -o existance
    bool doOutput = false;
    if(does_exist(args, "-o"))
    {
        outputFile = fopen(get_parameter(args, get_parameter_position(args, "-o") + 1), "w");
        printf("Output file: %s\n", get_parameter(args, get_parameter_position(args, "-o") + 1));
        doOutput = true;
    }
    
    
    // check -op exitance
    bool doShow = false;
    if(does_exist(args, "-op"))
    {
        doShow = true;
    }




    // checking files existance
    if(file == NULL)
    {       
        fclose(outputFile);
        raise_error("No valid input file path", 1);
        return 1;
    }

    if(outputFile == NULL && doOutput == true)
    {
        fclose(file);
        raise_error("Not valid output file path", 1);
        return 1;
    }
    
    // printing file size
    float fileSize = (float)getFileSize(file);
    printf("file size: %1.0f bytes\n", fileSize);
    printf("file size: %1.2f Kb\n", fileSize / 1000);
    printf("file size: %1.4f Mb\n\n", fileSize / 1000000);
    
    // printing column number
    printf("\t");
    if(doShow)
    {
        
        for(int i = 0; i < MAX_ROW; ++i)
        {
            if(i < 10)
            {
                printf("0%d ", i);
            }
            else
            {
                printf("%d ", i);
            }
        }
        printf("\n\n");
        printf("0\t");
    }
    int row = 1;
    
    
    // printing and/or saving it into text
    while ((ch = fgetc(file)) != EOF)
    {
        if(CurrentRow < MAX_ROW)
        {
            if(doOutput)
            {
                fprintf(outputFile, "%02X ", ch);
            }
            if(doShow)
            {
                printf("%02X ", ch);
            }
            CurrentRow++;
        }
        else
        {
            CurrentRow = 0;
            if(doOutput)
            {
                fprintf(outputFile, "\n");
            }
            if(doShow)
            {
                printf("\n%d\t", row);
            }
            row++;
        }
        
    }
    printf("\n");

    fclose(file);
    fclose(outputFile);
    
    return 0;
}