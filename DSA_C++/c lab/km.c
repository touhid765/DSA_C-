// (A number whose sum of factorials of digits equals the number)

#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    int num, temp, rem, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;

    while (temp != 0) {
        rem = temp % 10;
        sum += factorial(rem);
        temp /= 10;
    }

    if (sum == num)
        printf("%d is a Krishnamurthy number.", num);
    else
        printf("%d is not a Krishnamurthy number.", num);
    return 0;
}
