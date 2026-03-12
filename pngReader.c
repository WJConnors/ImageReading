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

    int expected[] = {137, 80, 78, 71, 13, 10, 26, 10};
    for (int i = 0; i < 8; i++) {
        int byte = fgetc(fptr);
        if (byte != expected[i]) {
            printf("Not a PNG");
            fclose(fptr);
            return 1;
        }
    }

    fclose(fptr);
    return 0;
}