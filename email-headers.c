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
    const char *headers[] = {
        "authentication-results:",
        "received:",
        "from:",
        "to:",
        "date:",
        "x-clx-shades:",
        "x-proofpoint-spam-details:"
    };
    int headerCount = sizeof(headers) / sizeof(headers[0]);

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

        for (int i = 0; i < headerCount; i++) {
            if (strncasecmp(buff, headers[i], strlen(headers[i])) == 0) {
                printf("%s\n", buff);
                break;
            }
        }
    }

    fclose(fptr);
    free(buff);

    return 0;
}
