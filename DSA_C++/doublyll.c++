#include <iostream>
#include <stdexcept>

// 1. Create the Node Structure
struct Node {
    int data;
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node

    // Constructor to easily create a new node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// 2. Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head; // Points to the first node
    Node* tail; // Points to the last node

public:
    // Constructor initializes an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to clean up memory and prevent leaks
    ~DoublyLinkedList() {
        while (head != nullptr) {
            pop_front();
        }
    }

    // 3. Add to Front (push_front)
    void push_front(int data) {
        Node* new_node = new Node(data);

        // If the list is completely empty
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }

        // Connect old head to new node
        new_node->next = head;
        head->prev = new_node;

        // Move head pointer to new node
        head = new_node;
    }

    // 4. Remove From Front (pop_front)
    int pop_front() {
        // Case 1: The list is empty
        if (head == nullptr) {
            throw std::runtime_error("List is empty. Cannot pop from front.");
        }

        Node* temp = head;
        int popped_data = temp->data;

        // Case 2: There is only one node in the list
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            // Case 3: There are multiple nodes
            head = head->next;
            head->prev = nullptr;
        }

        delete temp; // Free memory
        return popped_data;
    }

    // 5. Add to Back (push_back)
    void push_back(int data) {
        Node* new_node = new Node(data);

        // If the list is completely empty
        if (tail == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }

        // Connect old tail to new node
        tail->next = new_node;
        new_node->prev = tail;

        // Move tail pointer to new node
        tail = new_node;
    }

    // 6. Remove From Back (pop_back)
    int pop_back() {
        // Case 1: The list is empty
        if (tail == nullptr) {
            throw std::runtime_error("List is empty. Cannot pop from back.");
        }

        Node* temp = tail;
        int popped_data = temp->data;

        // Case 2: There is only one node in the list
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            // Case 3: There are multiple nodes
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp; // Free memory
        return popped_data;
    }

    // Helper method to print the list forward
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " <-> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// 7. Testing our Code
int main() {
    DoublyLinkedList list;

    std::cout << "--- Testing Push Operations ---" << std::endl;
    list.push_back(20);   // List: 20
    list.push_back(30);   // List: 20 <-> 30
    list.push_front(10);  // List: 10 <-> 20 <-> 30
    list.display();

    std::cout << "\n--- Testing Pop Operations ---" << std::endl;
    std::cout << "Popped from front: " << list.pop_front() << std::endl; // Removes 10
    list.display();                                                      // List: 20 <-> 30

    std::cout << "Popped from back: " << list.pop_back() << std::endl;   // Removes 30
    list.display();                                                      // List: 20

    return 0;
}
