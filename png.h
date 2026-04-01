#ifndef PNG_H
#define PNG_H

#include <stdio.h>
#include <stdbool.h>

bool readBytes(FILE* fptr, unsigned char* buffer, size_t readSize);
bool validatePNG(FILE* fptr);
bool readChunkSize(FILE* fptr, unsigned int* outSize);
unsigned int hexToInt(unsigned char chunk[4]);

#endif