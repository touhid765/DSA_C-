#include <iostream>

// Define a Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to create a node easily
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Define the Queue class
class Queue {
private:
    Node* frontNode;
    Node* backNode;
    int queueSize;

public:
    // Initialize an empty queue
    Queue() {
        frontNode = nullptr;
        backNode = nullptr;
        queueSize = 0;
    }

    // Add an element to the back (Push / Enqueue)
    void push(int value) {
        Node* newNode = new Node(value);
        
        // If queue is empty, new node is both front and back
        if (backNode == nullptr) {
            frontNode = newNode;
            backNode = newNode;
        } else {
            // Link the old back node to the new node
            backNode->next = newNode;
            // Update the back pointer
            backNode = newNode;
        }
        queueSize++;
    }

    // Remove an element from the front (Pop / Dequeue)
    void pop() {
        // Safety check: Cannot pop from an empty queue
        if (empty()) {
            std::cout << "Queue Underflow! Cannot pop.\n";
            return;
        }
        
        // Save the old front node to delete it later
        Node* temp = frontNode;
        
        // Move front to the next node
        frontNode = frontNode->next;
        
        // If the queue becomes empty, update back pointer too
        if (frontNode == nullptr) {
            backNode = nullptr;
        }
        
        // Free memory
        delete temp;
        queueSize--;
    }

    // Get the front element
    int front() {
        if (empty()) {
            std::cout << "Queue is empty! ";
            return -1; 
        }
        return frontNode->data;
    }

    // Get the back element
    int back() {
        if (empty()) {
            std::cout << "Queue is empty! ";
            return -1;
        }
        return backNode->data;
    }

    // Check if empty
    bool empty() {
        return frontNode == nullptr;
    }

    // Get current size
    int size() {
        return queueSize;
    }

    // Clean up memory when queue is destroyed
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }
};

int main() {
    Queue q;

    // Test pushing items
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Queue size: " << q.size() << "\n";
    std::cout << "Front item: " << q.front() << "\n";
    std::cout << "Back item: " << q.back() << "\n\n";

    // Test popping items
    std::cout << "Popping items sequentially:\n";
    while (!q.empty()) {
        std::cout << "Processing: " << q.front() << "\n";
        q.pop();
    }

    return 0;
}
