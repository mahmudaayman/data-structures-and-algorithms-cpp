/*
singly_linked_list.cpp

This program demonstrates a simple implementation of a Singly Linked List in C++.
Operations included:
1. Insert at the beginning
2. Insert at the end
3. Delete a node by value
4. Display the linked list
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Delete node by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        // If head node needs to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Value not found in the list." << endl;
        } else {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Display the linked list
    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Example usage
int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Linked List:" << endl;
    list.display();

    list.deleteByValue(20);
    cout << "After deleting 20:" << endl;
    list.display();

    return 0;
}
