#include <iostream>
using namespace std;

void printNums(int n){
    if(n==1){
        cout<<"1\n";
        return;
    }
    cout<<n<<" ";
    printNums(n-1);

}
int main(){
    printNums(4);
    return 0;
}



#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}


// sum of n numbers
int sum(int n){
    if(n==0){
        return 0;
    }
    return n+sum(n-1);
}


//fibonacci using recursion
#include <iostream>

// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n <= 1) {
        return n;
    }
    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms = 10; // Number of terms to display
    
    std::cout << "Fibonacci Sequence up to " << terms << " terms:\n";
    for (int i = 0; i < terms; ++i) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "The " << terms << "th Fibonacci number is: " << fibonacci(terms) << "\n";
    
    return 0;
}

// Example usage of the factorial and sum functions
int main() {
    int num = 5;

    // Calculate factorial
    int fact = factorial(num);
    std::cout << "Factorial of " << num << " is: " << fact << "\n";

    // Calculate sum of first n numbers
    int totalSum = sum(num);
    std::cout << "Sum of first " << num << " numbers is: " << totalSum << "\n";

    return 0;
}

//binary search using recursion
#include <iostream>
#include <vector>

// Recursive function to perform binary search
// Returns the index of target if found, otherwise -1
int binarySearch(const std::vector<int>& arr, int low, int high, int target) {
    // Base case: Search space is exhausted, element not found
    if (low > high) {
        return -1;
    }

    // Calculate mid-point (avoids integer overflow)
    int mid = low + (high - low) / 2;

    // Base case: Element found at mid
    if (arr[mid] == target) {
        return mid;
    }

    // If target is smaller, search the left half
    if (target < arr[mid]) {
        return binarySearch(arr, low, mid - 1, target);
    }

    // If target is larger, search the right half
    return binarySearch(arr, mid + 1, high, target);
}

int main() {
    // Note: The array MUST be sorted for binary search to work
    std::vector<int> numbers = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    
    int result = binarySearch(numbers, 0, numbers.size() - 1, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << "\n";
    } else {
        std::cout << "Element " << target << " not found in the array.\n";
    }

    return 0;
}
