#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr;
    long fileSize;
    char data[11]; 


    filePtr = fopen("example.txt", "rb");

    if (filePtr == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(filePtr, 0, SEEK_END);
    fileSize = ftell(filePtr);
    fseek(filePtr, -10, SEEK_END);
    fread(data, sizeof(char), 10, filePtr);
    data[10] = '\0';
    printf("The last 10 bytes of the file are:\n%s\n", data);
    fclose(filePtr);
    return 0;
}
