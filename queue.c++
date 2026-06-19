#include <iostream>
#include <queue> // Required header for std::queue

int main() {
    // 1. Initialization
    std::queue<int> myQueue;

    // 2. Enqueue Operations (Pushing data to the back)
    myQueue.push(10); // Queue status: [10]
    myQueue.push(20); // Queue status: [10, 20]
    myQueue.push(30); // Queue status: [10, 20, 30]

    // 3. Inspecting Metadata
    std::cout << "Current queue size: " << myQueue.size() << "\n"; // Outputs 3
    std::cout << "Element at the front: " << myQueue.front() << "\n"; // Outputs 10
    std::cout << "Element at the back: " << myQueue.back() << "\n\n";   // Outputs 30

    // 4. Dequeue & Process Loop (Destructive Traversal)
    std::cout << "Processing and emptying the queue:\n";
    while (!myQueue.empty()) {
        // View the item up next
        std::cout << "Processing front element: " << myQueue.front() << "\n";
        
        // Remove the item from the front line
        myQueue.pop(); 
    }

    // 5. Final State Validation
    if (myQueue.empty()) {
        std::cout << "\nQueue is now completely empty.\n";
    }

    return 0;
}
