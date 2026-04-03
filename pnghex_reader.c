#include <stdio.h>
#include <ctype.h>

#include "png.h"

/*
8 byte png sig
Then chunks:
    4 bytes size
    4 bytes ID
    x bytes depending on size
    4 bytes CRC
*/

static void readChunk(FILE* fptr, FILE* out) {
    unsigned int size;
    readChunkSize(fptr, &size);
    fprintf(out, "Chunk Size: %i\n", size);

    unsigned char type[4];
    readBytes(fptr, type, 4);
    
    for (int i = 0; i < 4; i++) {
        fprintf(out, "%02X ", type[i]);
    }
    fprintf(out, " | ");

    for (int i = 0; i < 4; i++) {
        if (isprint(type[i])) {
            fprintf(out, "%c", type[i]);
        } else {
            fprintf(out, ".");
        }
    }   

    fprintf(out, "\n");
}

int main() {
    FILE* fptr = fopen("pngTest.png", "rb");
    FILE* out = fopen("HEX.txt", "w");

    if (fptr == NULL) {
        printf("couldn't open file");
        return 1;
    }

    unsigned char sig[8];
    readBytes(fptr, sig, 8);

    for (int i = 0; i < 8; i++) {
        fprintf(out, "%02X ", sig[i]);
    }
    fprintf(out, " | ");

    for (int i = 0; i < 8; i++) {
        if (isprint(sig[i])) {
            fprintf(out, "%c", sig[i]);
        } else {
            fprintf(out, ".");
        }
    }   

    fprintf(out, "\n");

    readChunk(fptr, out);

    fclose(fptr);
    fclose(out);
}