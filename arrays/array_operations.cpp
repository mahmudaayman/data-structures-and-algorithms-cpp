
/*
array_operations.cpp

This program demonstrates basic array operations in C++:
1. Insert an element at a given position
2. Delete an element from a given position
*/

#include <iostream>
using namespace std;

void insertElement(int arr[], int& size, int element, int position, int capacity) {
    if (size >= capacity) {
        cout << "Array is full. Cannot insert element." << endl;
        return;
    }

    if (position < 0 || position > size) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
}

void deleteElement(int arr[], int& size, int position) {
    if (size == 0) {
        cout << "Array is empty. Cannot delete element." << endl;
        return;
    }

    if (position < 0 || position >= size) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int capacity = 10;
    int arr[capacity] = {10, 20, 30, 40};
    int size = 4;

    cout << "Original array: ";
    displayArray(arr, size);

    insertElement(arr, size, 25, 2, capacity);
    cout << "After insertion: ";
    displayArray(arr, size);

    deleteElement(arr, size, 3);
    cout << "After deletion: ";
    displayArray(arr, size);

    return 0;
}
