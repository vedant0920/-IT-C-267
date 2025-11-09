#include <stdio.h>
int main() {
    FILE *fs;
    FILE *fd;
    char ch;
    fs = fopen("input.txt", "r");
    if (fs == NULL) {
        printf("Source file not found!\n");
        return 1;
    }
    fd = fopen("output.txt", "w");
    while (1) {
        ch = fgetc(fs);
        if (ch == EOF) {
            break;
        } else {
            fputc(ch, fd);
        }
    }
    fclose(fs);
    fclose(fd);
    printf("Copied successfully!\n");
    return 0;
}
