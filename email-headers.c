#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Author: Zac Reeves
 * Created: 06-15-26
 * Updated: 06-15-26
 * Version: 1.0
 * Desc: Parse email headers for easy reading SPF, DMARC, and DKIM
 */

#define MAXBUFF 200000

int main() {
    FILE *fptr = fopen("test.txt", "r");
    if (fptr == NULL) {
        perror("An error occurred");
        return 1;
    }

    char *buff = malloc(MAXBUFF);

    printf("Printing email headers\n");
    while (fgets(buff, MAXBUFF, fptr) != NULL) {
        if (strcmp(buff, "\r\n") == 0 || strcmp(buff, "\n") == 0){
            break;
        }

        printf("%s", buff);
    }

    fclose(fptr);
    free(buff);
    return 0;
}
