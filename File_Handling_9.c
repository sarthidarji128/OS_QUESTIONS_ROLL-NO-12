#include <stdio.h>

int main() {
    FILE *file;
    char filePath[100];
    int ch, lines = 0;

    printf("Enter the file path: ");
    scanf("%99s", filePath);

    file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);
    printf("Number of lines: %d\n", lines);
    return 0;
}
