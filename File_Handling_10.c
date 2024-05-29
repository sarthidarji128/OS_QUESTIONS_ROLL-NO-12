#include <stdio.h>

int file_exists(const char *filename) {
    FILE *file;
    if ((file = fopen(filename, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    char filePath[100];

    printf("Enter the file path: ");
    scanf("%99s", filePath);

    if (file_exists(filePath)) {
        printf("File exists.\n");
    } else {
        printf("File does not exist.\n");
    }

    return 0;
}
