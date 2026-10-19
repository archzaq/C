#include <stdio.h>
#include <string.h>

char * reverse(char *s){
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

int main(int argc, char *argv[]) {
    // need to setup input 
    char str[] = "bonzai";
    char newReversed[sizeof str];

    strcpy(newReversed, str);
    reverse(newReversed);

    printf("Initial String: %s\n", str);
    printf("New String: %s\n", newReversed);
    return 0;
}
