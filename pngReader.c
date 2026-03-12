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

    char sig[sizeof(PNG_SIG) - 1];
    bool isPNG = fread(sig, 1, sizeof(sig), fptr) == sizeof(sig) &&
           memcmp(sig, PNG_SIG, sizeof(sig)) == 0;

    printf("%d", isPNG);

    fclose(fptr);
    return 0;
}