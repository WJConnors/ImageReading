#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    FILE* fptr = fopen("pngtest.png", "rb");

    if (fptr == NULL) {
        printf("couldn't open image file");
        return 1;
    }

    printf("opened file\n");

    for (int i = 0; i < 8; i++) {
        int byte = fgetc(fptr);
        printf("%02x\n", byte);
    }

    fclose(fptr);
    return 0;
}