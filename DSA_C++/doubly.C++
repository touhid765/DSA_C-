#include <iostream>

// 1. Define the Node structure
struct Node {
    int data;     // The actual value stored in the node
    Node* prev;   // Pointer to the previous node in the list
    Node* next;   // Pointer to the next node in the list

    // Constructor to quickly set up a new node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// 2. Define the Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;   // Points to the very first node (nullptr if empty)
    Node* tail;   // Points to the very last node (nullptr if empty)

public:
    // Constructor initializes an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
};

// 3. Instantiate the list in your main function
int main() {
    // This creates an empty doubly linked list in memory
    DoublyLinkedList myList; 
    
    std::cout << "Doubly Linked List successfully initialized!" << std::endl;
    return 0;
}
