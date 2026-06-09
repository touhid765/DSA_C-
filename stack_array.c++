#include <iostream>
using namespace std;

class Stack {
    int top;
    int maxSize;
    int* array;

public:
    Stack(int size) {
        maxSize = size;
        array = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] array;
    }

    void push(int x) {
        if (top >= maxSize - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        array[++top] = x;
        cout << x << " pushed\n";
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return array[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return array[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.peek() << "\n";
    cout << "Popped: " << s.pop() << "\n";
    return 0;
}   