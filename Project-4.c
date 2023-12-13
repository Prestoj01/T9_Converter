/*Preston Johnson
CPSC 1071: 05
Team Number 2 CTRL+C CTRL+V
Date: 12/4/2023*/

#include <stdio.h>
#include <stdlib.h>
#include "PhoneNum.h"

int main(int argc, char *argv[]) {
    //sets default flag
    char flag = 'd';

    //checks if there are 2 or 3 argc
    if (argc != 4 && argc > 1) {
        //check for help flag
        if (argv[1][1] == 'h') {
            printf("PhoneNum T9 Conversion Tool. Usage:\n");
            printf("PhoneNum.exe <input file> <output file> [-L]\n");
            printf("-L Sets input type as letters instead of digits\n");
            printf("-h To get help\n");
        }
        //check if they only put one file
        else if (argc == 2) {
            printf("No output file given\n");
            printf("Use -h to get help\n");
        }
    }
    //checks if they put no files or flag
    if (argc == 1) {
            printf("No input file given\n");
            printf("No output file given\n");
            printf("Use -h to get help\n");
        }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    //makes sure files open
    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    //gets flag value
    if (argc == 4) {
        flag = argv[3][1]; // Extract the flag from the command line argument
    }

    //uses conversionT9 method
    conversionT9(inputFile, outputFile, flag);
    
    //closes the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
