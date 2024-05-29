#include <stdio.h>

int main() {
    FILE *filePtr;
    filePtr = fopen("newfile.txt", "w");

    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fclose(filePtr);

    printf("File created and closed successfully.\n");

    return 0;
}
