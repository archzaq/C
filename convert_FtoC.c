#include <stdio.h>
#include <stdlib.h>

/* Author: Zac Reeves
 * Created: 06-01-26
 * Updated: 06-05-26
 * Version: 1.2
 * Desc: Convert Fahrenheit to Celsius
 *       Takes min, max, and step from command line
 */

void usage(char *argv[]) {
    printf("\nUsage: %s <min> <max> <step (optional)>\n\n", argv[0]);
}

int main(int argc, char *argv[]) {
    int fahr, celsius;
    int lower, upper, step;

    if (argc < 3) {
        usage(&argv[0]);
        return 1;
    } else if (argc == 3) {
        step = 1;
    } else if (argc == 4) {
        step = atoi(argv[3]);
    } else {
        printf("\nToo many arguments!\n");
        usage(&argv[0]);
        return 1;
    }

    lower = atoi(argv[1]);
    upper = atoi(argv[2]);
    if (lower < upper) {
        fahr = lower;
        while (fahr <= upper) {
            celsius = 5 * (fahr-32) / 9;
            printf("%d\t%d\n", fahr, celsius);
            fahr = fahr + step;
        }
    } else {
        printf("\nError: The Minimum must be lower than the Maxmimum\n");
        usage(&argv[0]);
    }

    return 0;
}
