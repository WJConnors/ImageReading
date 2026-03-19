#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PNG_SIG "\x89PNG\r\n\x1a\n"

int main() {
    FILE* fptr = fopen("pngTest.png", "rb");

    if (fptr == NULL) {
        printf("couldn't open image file");
        return 1;
    }

    printf("opened file\n");
//Refactor into validator function
    char sig[sizeof(PNG_SIG) - 1];
    bool isPNG = fread(sig, 1, sizeof(sig), fptr) == sizeof(sig) &&
           memcmp(sig, PNG_SIG, sizeof(sig)) == 0;

    printf("%d\n", isPNG);


    char chunkSize[4];

    if (fread(chunkSize, 1, 4, fptr) != 4) {
        printf("Failed to read chunk size\n");
        fclose(fptr);
        return 1;
    }

// Print raw bytes as a test
    printf("Raw bytes: ");
    for (int i = 0; i < 4; i++) {
        printf("%02X ", (unsigned char)chunkSize[i]);
    }
    printf("\n");

// Convert to integer
// Need to understand better and refactor into generic function
    unsigned int size =
        ((unsigned char)chunkSize[0] << 24) |
        ((unsigned char)chunkSize[1] << 16) |
        ((unsigned char)chunkSize[2] << 8)  |
        ((unsigned char)chunkSize[3]);

    printf("Chunk size: %u\n", size);

    fclose(fptr);
    return 0;
}