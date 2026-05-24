// sum of series

#include <stdio.h>

int main() {
    int n;
    double sum = 0.0;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        sum += 1.0 / i;

    printf("Sum = %.2f", sum);
    return 0;
}
