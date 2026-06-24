#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;

    // Helper function to move elements from input to output when needed
    void shiftStacks() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue
    void pop() {
        if (empty()) {
            std::cout << "Queue Underflow\n";
            return;
        }
        shiftStacks();
        output.pop();
    }

    // Get the front element
    int peek() {
        if (empty()) return -1;
        shiftStacks();
        return output.top();
    }

    // Return whether the queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front element: " << q.peek() << "\n"; // Expected: 10

    q.pop();
    std::cout << "Front element after pop: " << q.peek() << "\n"; // Expected: 20

    return 0;
}
