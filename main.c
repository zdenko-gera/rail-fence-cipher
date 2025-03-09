#include <stdio.h>

int main() {
    char rawText[100];
    int railKey = 1;

    printf("::Rail Fence Cipher::\n\n");
    printf("Add meg a kodolni kivant szoveget: \n");

    fgets(rawText, sizeof(rawText), stdin);

    printf("Add meg a rail key-t: ");
    scanf("%d", &railKey);

    printf("SZOVEG: %s", rawText);
    printf("RAIL KEY: %d", railKey);

    return 0;
}
