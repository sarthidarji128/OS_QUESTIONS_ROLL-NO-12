#include <unistd.h>
#include <sys/types.h>

int main() {
    char *file_path = "example.txt";
    uid_t new_owner = 501; 
    gid_t new_group = 501; 

    chown(file_path, new_owner, new_group);

    return 0;
}

