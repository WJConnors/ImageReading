#include <stdio.h>
#include <stdbool.h>

#include "png.h"

int main() {
    FILE* fptr = fopen("pngTest.png", "rb");

    if (fptr == NULL) {
        printf("couldn't open image file");
        return 1;
    }

    printf("opened file\n");

    bool isPNG = validatePNG(fptr);
    printf("Is PNG: %d\n", isPNG);

    unsigned int size;
    if (!readChunkSize(fptr, &size)) {
        printf("Filed to read chunk size");
        
    }

    printf("Chunk size: %i\n", size);

    fclose(fptr);
    return 0;
}