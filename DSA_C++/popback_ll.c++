#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Removes the last node from the list
void popBack(Node*& head) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot pop.\n";
        return;
    }

    // If there is only one node in the list
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // Traverse to find the second-to-last node
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;     // Free the memory of the last node
    temp->next = nullptr;  // Make the second-to-last node the new end
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

    popBack(head);
    std::cout << "After Pop Back: ";
    printList(head); // Output: 10 -> 20 -> nullptr
    return 0;
}
