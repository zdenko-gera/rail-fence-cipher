#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char rawText[256];
    int railKey = 1;

    printf("::Rail Fence Cipher::\n\n");
    printf("Add meg a kodolni kivant szoveget: \n");

    fgets(rawText, sizeof(rawText), stdin);

    printf("Add meg a rail key-t: ");
    scanf("%d", &railKey);

    printf("SZOVEG: %s", rawText);
    printf("RAIL KEY: %d\n", railKey);

    char grid[railKey][strlen(rawText)];
    int j = 0;
    bool growingIndex = true;

    for (int i = 0; i < strlen(rawText); i++) {
        for (int l = 0; l < railKey; l++) {
            grid[l][i] = '-';
        }
    }

    for (int i = 0; i < strlen(rawText); i++) {

        grid[j][i] = rawText[i];

        if (growingIndex && j < (railKey - 1)) {
            j++;
            continue;
        } else if (growingIndex && j == (railKey - 1)) {
            growingIndex = false;
            j--;
            continue;
        }

        if (growingIndex == false && j > 0) {
            j--;
            continue;
        } else if (growingIndex == false && j == 0) {
            growingIndex = true;
            j++;
            continue;
        }
    }

    char cipheredText[256];

    for (int k = 0; k < railKey; k++) {
        for (int i = 0; i < strlen(rawText); i++) {
            if (grid[k][i] != ' ') {
                strcat(cipheredText, grid[k][i]);
            }
            printf("%c", grid[k][i]);
        }
        printf("\n");

    }

    return 0;
}
