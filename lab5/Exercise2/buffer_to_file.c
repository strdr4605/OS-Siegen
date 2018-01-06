#include <stdio.h>

int main () {
    FILE * pFile;
    char buffer[] = "This is the content of the file";
    int position = 20;
    pFile = fopen ("myfile.txt", "w");
    fwrite (buffer + position, sizeof(char), sizeof(buffer) - position - 1, pFile);
    fclose (pFile);
    return 0;
}
