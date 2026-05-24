//sum of series



#include <stdio.h>

int fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    int n, sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        sum += fact(i);

    printf("Sum = %d", sum);
    return 0;
}
