#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Removes the first node from the list
void popFront(Node*& head) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot pop.\n";
        return;
    }

    Node* temp = head; // Store the current head to delete it later
    head = head->next; // Move head to the next node
    delete temp;       // Free memory of the old head
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    // Manually setting up a list: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    std::cout << "Original List: ";
    printList(head);

    popFront(head);
    std::cout << "After Pop Front: ";
    printList(head); // Output: 20 -> 30 -> nullptr
    return 0;
}
