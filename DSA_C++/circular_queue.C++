#include <iostream>

class CircularQueue {
private:
    int* arr;
    int frontIdx;
    int rearIdx;
    int capacity;
    int currentSize;

public:
    // Initialize the queue with a fixed capacity
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIdx = -1;
        rearIdx = -1;
        currentSize = 0;
    }

    // Check if the queue is full
    bool isFull() {
        return currentSize == capacity;
    }

    // Check if the queue is empty
    bool empty() {
        return currentSize == 0;
    }

    // Add an item to the back (Push / Enqueue)
    void push(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow! Cannot push " << value << "\n";
            return;
        }

        // If the queue is empty, move front index to 0
        if (frontIdx == -1) {
            frontIdx = 0;
        }

        // Use modulo to wrap around to the start of the array if needed
        rearIdx = (rearIdx + 1) % capacity;
        arr[rearIdx] = value;
        currentSize++;
    }

    // Remove an item from the front (Pop / Dequeue)
    void pop() {
        if (empty()) {
            std::cout << "Queue Underflow! Cannot pop.\n";
            return;
        }

        // Check if this was the very last item in the queue
        if (frontIdx == rearIdx) {
            frontIdx = -1;
            rearIdx = -1;
        } else {
            // Use modulo to wrap the front index around if needed
            frontIdx = (frontIdx + 1) % capacity;
        }
        currentSize--;
    }

    // Get the front element
    int front() {
        if (empty()) {
            std::cout << "Queue is empty! ";
            return -1;
        }
        return arr[frontIdx];
    }

    // Get the back element
    int back() {
        if (empty()) {
            std::cout << "Queue is empty! ";
            return -1;
        }
        return arr[rearIdx];
    }

    // Get the current number of elements
    int size() {
        return currentSize;
    }

    // Free the allocated array memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    // Create a circular queue that holds up to 3 items
    CircularQueue cq(3);

    // Push 3 items to fill the queue
    cq.push(10);
    cq.push(20);
    cq.push(30);

    // This push will fail because the queue is full
    cq.push(40); 

    std::cout << "Front item: " << cq.front() << "\n"; // Outputs 10
    
    // Pop one item to free up the first array slot
    cq.pop(); 

    // This push succeeds because the index wraps around to slot 0
    cq.push(40); 

    std::cout << "New Back item: " << cq.back() << "\n"; // Outputs 40
    std::cout << "Current size: " << cq.size() << "\n";   // Outputs 3

    return 0;
}
