#include "png.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define PNG_SIG "\x89PNG\r\n\x1a\n"

bool validatePNG(FILE* fptr) {
    unsigned char sig[sizeof(PNG_SIG) - 1];
    return fread(sig, 1, sizeof(sig), fptr) == sizeof(sig) &&
           memcmp(sig, PNG_SIG, sizeof(sig)) == 0;
}