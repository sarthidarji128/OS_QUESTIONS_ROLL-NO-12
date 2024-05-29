#include <stdio.h>

int main() {
    FILE *fp;

   
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Could not open file.txt for reading.\n");
    } else {
        printf("Opened file.txt for reading.\n");
        fclose(fp);
    }

   
    fp = fopen("file.txt", "w");
    if (fp == NULL) {
        printf("Could not open file.txt for writing.\n");
    } else {
        printf("Opened file.txt for writing.\n");
        fclose(fp);
    }


    fp = fopen("file.txt", "a");
    if (fp == NULL) {
        printf("Could not open file.txt for appending.\n");
    } else {
        printf("Opened file.txt for appending.\n");
        fclose(fp);
    }


    fp = fopen("file.txt", "r+");
    if (fp == NULL) {
        printf("Could not open file.txt for reading and writing.\n");
    } else {
        printf("Opened file.txt for reading and writing.\n");
        fclose(fp);
    }

    fp = fopen("file.txt", "w+");
    if (fp == NULL) {
        printf("Could not open file.txt for reading and writing.\n");
    } else {
        printf("Opened file.txt for reading and writing.\n");
        fclose(fp);
    }

    return 0;
}
