#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[256];
    while (1) {
        printf("-> ");
        fgets(command, 256, stdin);
        if (strncmp(command, "add ", 4) == 0) {
            char character;
            int frequency;
            sscanf(command + 4, "%c %d", &character, &frequency);
            addCharacter(character, frequency);
        } else if (strncmp(command, "calc", 4) == 0) {
            calculateHuffmanCodes();
        } else if (strncmp(command, "print", 5) == 0) {
            printHuffmanTable();
        } else if (strncmp(command, "cod ", 4) == 0) {
            char str[256];
            sscanf(command + 4, "%s", str);
            encodeString(str);
        } else if (strncmp(command, "dec ", 4) == 0) {
            char bits[256];
            sscanf(command + 4, "%s", bits);
            decodeBits(bits);
        } else if (strncmp(command, "clear", 5) == 0) {
            clearTable();
        } else if (strncmp(command, "exit", 4) == 0) {
            break;
        } else {
            printf("Comando inválido.\n");
        }
    }
    return 0;
}