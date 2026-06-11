#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() { top = nullptr; }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed\n";
    }

    int pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return -1;
        }
        Node* temp = top;
        int val = top->data;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        if (!top) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(100);
    s.push(200);
    cout << "Top element: " << s.peek() << "\n";
    cout << "Popped: " << s.pop() << "\n";
    return 0;
}   