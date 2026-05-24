#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, rem, n = 0;
    double result = 0.0;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;

    while (temp != 0) {
        temp /= 10;
        ++n;
    }

    temp = num;
    while (temp != 0) {
        rem = temp % 10;
        result += pow(rem, n);
        temp /= 10;
    }

    if ((int)result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);
    return 0;
}
