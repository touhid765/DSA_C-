

// int main(){
//     int marks[5]={88,44,66,33,22};
//     int size=5;

//     for(int i=0; i<size; i++){
//         cout << marks[i] <<endl;
//     }
// }

// smallest and largest


// #include<iostream>
// #include <climits>
// using namespace std;
// int main(){
//     int nums[]={5,15,22,-15,24,1};
//      int size=6;

//      int smallest = INT_MAX;

//      for(int i=0; i<size; i++){
//         if (nums[i] < smallest) {
//             smallest = nums[i];
//         }
//      }

//      cout << "smallest = "<< smallest << endl;
//      return 0;
// }     

#include <iostream>
using namespace std;

// Function to perform linear search
// Returns the index of the element if found, otherwise returns -1
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return its index
        }
    }
    return -1; // Target not found after checking all elements
}

int main() {
    int data[] = {12, 45, 7, 23, 9, 31};
    int n = sizeof(data) / sizeof(data[0]);
    int key = 7;

    int result = linearSearch(data, n, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
