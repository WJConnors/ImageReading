#include <stdio.h>
#include <ctype.h>

#include "png.h"

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

    fclose(fptr);
    fclose(out);
}