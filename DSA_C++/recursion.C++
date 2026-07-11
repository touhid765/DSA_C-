#include <iostream>
#include <vector>

// Helper recursive function to find and print all subsets
void printSubsetsRecursive(const std::vector<int>& arr, int index, std::vector<int>& currentSubset) {
    // Base Case: If we have processed all elements, print the current subset
    if (index == arr.size()) {
        std::cout << "[ ";
        for (int num : currentSubset) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
        return;
    }

    // Choice 1: "Pick" / Include the current element
    currentSubset.push_back(arr[index]);
    printSubsetsRecursive(arr, index + 1, currentSubset);

    // Backtrack: Remove the element to explore the "Don't Pick" choice
    currentSubset.pop_back();

    // Choice 2: "Don't Pick" / Exclude the current element
    printSubsetsRecursive(arr, index + 1, currentSubset);
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    std::vector<int> currentSubset;

    std::cout << "All possible subsets:\n";
    // Start recursion from index 0
    printSubsetsRecursive(arr, 0, currentSubset);

    return 0;
}
 

//duplicate element

#include <iostream>
#include <vector>
#include <algorithm>

// Helper recursive function to find unique subsets
void printUniqueSubsets(const std::vector<int>& arr, int index, std::vector<int>& currentSubset) {
    // Print the subset generated at the current recursive level
    std::cout << "[ ";
    for (int num : currentSubset) {
        std::cout << num << " ";
    }
    std::cout << "]\n";

    // Loop through the remaining elements to form deeper branches
    for (int i = index; i < arr.size(); ++i) {
        // Skip duplicates: If this element is identical to the previous one 
        // within the same recursive loop level, ignore it.
        if (i > index && arr[i] == arr[i - 1]) {
            continue;
        }

        // Include the element
        currentSubset.push_back(arr[i]);
        
        // Move to the next index recursively
        printUniqueSubsets(arr, i + 1, currentSubset);
        
        // Backtrack: Remove the element to try other options
        currentSubset.pop_back();
    }
}

int main() {
    std::vector<int> arr = {1, 2, 2};
    
    // 1. Crucial step: Sort the array so duplicates sit next to each other
    std::sort(arr.begin(), arr.end());
    
    std::vector<int> currentSubset;
    std::cout << "All unique subsets:\n";
    
    // 2. Start the recursion from index 0
    printUniqueSubsets(arr, 0, currentSubset);

    return 0;
}

//permutation of an array
#include <iostream>
#include <vector>

// Helper recursive function to find and print all permutations
void printPermutations(std::vector<int>& arr, int index) {
    // Base Case: If the current index reaches the end, a unique ordering is complete
    if (index >= arr.size()) {
        std::cout << "[ ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
        return;
    }

    // Loop through the remaining elements to swap with the current index
    for (int i = index; i < arr.size(); ++i) {
        // Swap the current index element with the i-th element
        std::swap(arr[index], arr[i]);

        // Recursively generate permutations for the rest of the array
        printPermutations(arr, index + 1);

        // Backtrack: Swap back to restore the original state for the next iteration
        std::swap(arr[index], arr[i]);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3};

    std::cout << "All permutations:\n";
    // Start recursion from index 0
    printPermutations(arr, 0);

    return 0;
}
