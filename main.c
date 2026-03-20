#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "png.h"

int main() {
    FILE* fptr = fopen("pngTest.png", "rb");

    if (fptr == NULL) {
        printf("couldn't open image file");
        return 1;
    }

    printf("opened file\n");

    bool isPNG = validatePNG(fptr);
    printf("%d\n", isPNG);

    int size = readChunkSize(fptr);

    printf("Chunk size: %i\n", size);

    fclose(fptr);
    return 0;
}