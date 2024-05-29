#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char buffer[11];
    int bytes_read;


    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the first 10 bytes from the file
    bytes_read = fread(buffer, sizeof(char), 10, file);
    buffer[bytes_read] = '\0'; // Null-terminate the string

    // Check for reading errors
    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Print the bytes read
    printf("First 10 bytes of the file:\n%s\n", buffer);

    // Close the file
    fclose(file);
    return EXIT_SUCCESS;
}
