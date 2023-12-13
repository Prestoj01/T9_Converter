#ifndef PHONENUM_H
#define PHONENUM_H

#include <stdio.h>

void conversionT9(FILE *in, FILE *out, char type);
char *toWord(char *digits);
char *toDigits(char *word);
char *getNextChars(FILE *in);

#endif