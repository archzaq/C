#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Author:  Zac Reeves
 * Created: 06-01-26
 * Updated: 06-09-26
 * Version: 1.1
 * Desc: This program's purpose is to convert a decimal string to binary.
 *       Takes the number from the command line.
 */

void usage(char *argv[]) {
    printf("Usage: %s <number>\n\n", argv[0]);
}

int convertBin(unsigned long long num, char binaryArray[]) {
    int count = 0;
    int remain;
    if (num == 0) {
        binaryArray[30 - count] = 0 + '0';
        count++;
    }
    while ((num > 0) && (count < 31)) {
        remain = num % 2;
        num = num / 2;
        binaryArray[30 - count] = remain + '0';
        count++;
    }
    binaryArray[31] = '\0';
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("\nPlease input a number!\n");
        usage(&argv[0]);
        return 1;
    } else if (argc > 2) {
        printf("\nToo many arguments!\n");
        usage(&argv[0]);
        return 1;
    }

    unsigned long long initialNum = strtoull(argv[1], NULL, 10);
    char binaryArray[32];

    printf("\nDecimal:\t%llu\n", initialNum);
    printf("Binary:\t\t");

    int count = convertBin(initialNum, binaryArray);
    assert(31 - count >= 0);
    printf("%s\n\n", &binaryArray[31 - count]);

    return 0;
}
