#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Adds a node to the front of the list
void pushFront(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head; // Point new node to the current head
    head = newNode;       // Update head to point to the new node
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    Node* head = nullptr;

    pushFront(head, 30);
    pushFront(head, 20);
    pushFront(head, 10);

    std::cout << "After Push Front: ";
    printList(head); // Output: 10 -> 20 -> 30 -> nullptr
    return 0;
}
