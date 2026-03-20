#include "png.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define PNG_SIG "\x89PNG\r\n\x1a\n"

static bool readBytes(FILE* fptr, unsigned char* buffer, size_t readSize) {
    return fread(buffer, 1, readSize, fptr) == readSize;
}

bool validatePNG(FILE* fptr) {
    unsigned char sig[sizeof(PNG_SIG) - 1];
    return readBytes(fptr, sig, sizeof(sig)) &&
            memcmp(sig, PNG_SIG, sizeof(sig)) == 0;
}