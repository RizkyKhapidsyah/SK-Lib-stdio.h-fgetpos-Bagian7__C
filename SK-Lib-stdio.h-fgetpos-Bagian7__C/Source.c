#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>

/*
    Source by BelajarCPP
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main(void) {
    FILE* stream;
    fpos_t pos;
    char   buffer[20];

    if (fopen_s(&stream, "testingFile.txt", "rb")) {
        perror("Trouble opening file");
        return -1;
    }

    // Read some data and then save the position.
    fread(buffer, sizeof(char), 8, stream);
    if (fgetpos(stream, &pos) != 0) {
        perror("fgetpos error");
        return -1;
    }

    fread(buffer, sizeof(char), 13, stream);
    printf("after fgetpos: %.13s\n", buffer);

    // Restore to old position and read data
    if (fsetpos(stream, &pos) != 0) {
        perror("fsetpos error");
        return -1;
    }

    fread(buffer, sizeof(char), 13, stream);
    printf("after fsetpos: %.13s\n", buffer);
    fclose(stream);

    _getch();
    return 0;
}