#include <stdio.h>
#include <sys/stat.h>

int main() {
    char *file_path = "example.txt";
    int mode = 0777; 
    if (chmod(file_path, mode) < 0) {
        perror("Error ");
        return 1;
    }
    return 0;
}
