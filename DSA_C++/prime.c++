// check a number is prime or not

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 29;
    int cnt = 0;
    
    // If number is less than/equal to 1,
    // it is not prime
    if (n <= 1)
        cout << n << " is NOT prime";
    else {

        // Count the divisors of n
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                cnt++;
        }

        // If n is divisible by more than 2 
        // numbers then it is not prime
        if (cnt > 2)
            cout << n << " is NOT prime";

        // else it is prime
        else
            cout << n << " is prime";
    }
    return 0;
}