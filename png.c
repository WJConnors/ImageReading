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
//TODO: Extract hex to into into own function
bool readChunkSize(FILE* fptr, unsigned int* outSize) {
    unsigned char chunk[4];
    if (!readBytes(fptr, chunk, 4)) {
        return false;
    }

    *outSize =
        ((unsigned int)chunk[0] << 24) |
        ((unsigned int)chunk[1] << 16) |
        ((unsigned int)chunk[2] << 8)  |
        ((unsigned int)chunk[3]);

    return true;
}