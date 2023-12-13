/*Preston Johnson
CPSC 1071: 05
Team Number 2 CTRL+C CTRL+V
Date: 12/4/2023*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PhoneNum.h"

//main method for T9 conversion
void conversionT9(FILE *in, FILE *out, char type) {
    //gets the first number and puts first in the output
    char *input = getNextChars(in);
    fprintf(out, "%s", input);
    free(input);

    input = getNextChars(in);

    //loop to continue getting inputs until the input file is through
    while (input != NULL) {
        //process the input based on the type
        if (type == 'd' || type == 'D') {
            //convert from digits to words
            char *word = toWord(input);
            fprintf(out, "%s\n", word);
            free(word);
        } 
        else if (type == 'l' || type == 'L') {
            //convert from letters to digits
            char *digits = toDigits(input);
            fprintf(out, "%s\n", digits);
            free(digits);
        }

        //frees current input and gets input for next loop
        free(input);
        input = getNextChars(in);
    }
}

//function to convert digits to words
char *toWord(char *digits) {
    char *word = malloc(strlen(digits) + 1);
    
    if (word == NULL) {
        //handle memory allocation failure
        return NULL;
    }

    //sets pointer equal to word
    char *ptr = word;

    //while loop that continues till null
    while (*digits != '\0') {
        int counter = -1;
        char *temp = digits;

        //check for the end of the current digit and counts how many times the number repeats
        while (*temp != '\0' && *temp != '-' && *temp!= '\n') {
            counter++;
            temp++;
        }

        if (*digits >= '2' && *digits <= '9') {
            int num = *digits - '0';
            int offset = (num - 2) * 3;

            //if number greater than seven offset by 1 because 7 has 4 letters instead of 3
            if (num > 7) {
                offset++;
            }

            //adds the offset and counter to a to get the right letter
            char ch = 'a' + offset + counter;
            *ptr++ = ch;

            //continues the temp if it is on a -
            if (*temp == '-') {
                temp++;
            }
            
            //sets address of temp to address of digits
            digits = temp;
        } 
        else {
            digits++;
        }
    }

    //adds null to the end of word
    *ptr = '\0';

    return word;
}

//function to convert word to digits
char *toDigits(char *word) {
    char *digits = malloc(strlen(word) * 4 + 1); // Maximum possible length, each letter maps to 4 characters
    if (digits == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    char *ptr = digits;

    //while loop to go through entire word
    while (*word != '\0') {
        //adds correct number if letter is between a and c
        while (*word >= 'a' && *word <= 'c') {
            (*word)--;
            *ptr++ = '2';
        }
        //adds correct number if letter is between d and f
        while (*word >= 'd' && *word <= 'f') {
            (*word)--;
            *ptr++ = '3';
        }
        //adds correct number if letter is between g and i
        while (*word >= 'g' && *word <= 'i') {
            (*word)--;
            *ptr++ = '4';
        }
        //adds correct number if letter is between j and l
        while (*word >= 'j' && *word <= 'l') {
            (*word)--;
            *ptr++ = '5';
        }
        //adds correct number if letter is between m and o
        while (*word >= 'm' && *word <= 'o') {
            (*word)--;
            *ptr++ = '6';
        }
        //adds correct number if letter is between p and s
        while (*word >= 'p' && *word <= 's') {
            (*word)--;
            *ptr++ = '7';
        }
        //adds correct number if letter is between t and v
        while (*word >= 't' && *word <= 'v') {
            (*word)--;
            *ptr++ = '8';
        }
        //adds correct number if letter is between w and z
        while (*word >= 'w' && *word <= 'z') {
            (*word)--;
            *ptr++ = '9';
        }

        //if statement to add dashes in correct spots
        if (*word != '\0') {
            *ptr++ = '-';
            word++;
        }
    }

    //subtracts the last -
    *ptr--;

    *ptr = '\0';

    return digits;
}

//function to get next characters in the file
char *getNextChars(FILE *in) {
    //large array to get the input
    char buffer[256];

    if (fgets(buffer, sizeof(buffer), in) != NULL) {
        size_t len = strlen(buffer);
        char *result = malloc(len + 1);
        strcpy(result, buffer);
        return result;
    }

    return NULL;
}