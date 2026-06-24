#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    // Push element x onto stack
    void push(int x) {
        q.push(x);
        int s = q.size();
        
        // Rotate the queue to bring the new element to the front
        for (int i = 0; i < s - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack
    void pop() {
        if (q.empty()) {
            std::cout << "Stack Underflow\n";
            return;
        }
        q.pop();
    }

    // Get the top element
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    // Return whether the stack is empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    std::cout << "Top element: " << st.top() << "\n"; // Expected: 30

    st.pop();
    std::cout << "Top element after pop: " << st.top() << "\n"; // Expected: 20

    return 0;
}
