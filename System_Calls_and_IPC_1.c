#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file_desc = open("e.txt", O_WRONLY | O_APPEND);
    if (file_desc < 0) {
        printf("Error opening the file\n");
        return 1;
    }

    int copy_desc = dup(file_desc);

    write(file_desc, "This will be output to the file named example.txt\n", 51);

    write(copy_desc, "This will also be output to the file named example.txt\n", 55);

    close(file_desc);
    close(copy_desc);

    return 0;
}




