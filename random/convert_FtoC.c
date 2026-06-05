#include <stdio.h>

/* Author: Zac Reeves
 * Created: 06-01-26
 * Updated: 06-01-26
 * Desc: Convert Fahrenheit to Celsius
 */

int main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
