#ifndef PNG_H
#define PNG_H

#include <stdio.h>
#include <stdbool.h>

bool validatePNG(FILE* fptr);
bool readChunkSize(FILE* fptr, unsigned int* outSize);

#endif