#include <stdio.h>

int main() {
    FILE *filePtr;
    filePtr = fopen("example.txt", "a");

    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(filePtr, "End of File\n");
    fclose(filePtr);
    printf("The text 'End of File' has been appended to 'example.txt'.\n");

    return 0;
}
