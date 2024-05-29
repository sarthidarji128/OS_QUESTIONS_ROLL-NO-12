#include <stdio.h>

int main() {
    FILE *filePtr;

    filePtr = fopen("output.txt", "w");

    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(filePtr, "Hello, World!\n");

    fclose(filePtr);

    printf("The text has been written to 'output.txt'.\n");

    return 0;
}
