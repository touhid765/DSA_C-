#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Adds a node to the end of the list
void pushBack(Node*& head, int val) {
    Node* newNode = new Node(val);

    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to find the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to the new node
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

    pushBack(head, 10);
    pushBack(head, 20);
    pushBack(head, 30);

    std::cout << "After Push Back: ";
    printList(head); // Output: 10 -> 20 -> 30 -> nullptr
    return 0;
}
