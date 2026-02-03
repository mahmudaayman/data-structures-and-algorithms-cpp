/*
stack.cpp

This program demonstrates a simple stack implementation in C++ using an array.
Operations included:
1. Push (insert element)
2. Pop (remove element)
3. Peek (view top element)
4. Display stack
*/

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Push element onto stack
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow. Cannot push element." << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop element from stack
    void pop() {
        if (top == -1) {
            cout << "Stack underflow. Cannot pop element." << endl;
            return;
        }
        top--;
    }

    // Peek top element
    void peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    // Display stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

// Example usage
int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();
    stack.peek();

    stack.pop();
    cout << "After popping one element:" << endl;
    stack.display();

    return 0;
}
