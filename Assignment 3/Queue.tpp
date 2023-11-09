#include "Queue.h"
#include <stdexcept>

// Constructor
template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), count(0) {}

// Destructor
template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Inserts a new element at the rear of the queue
template <typename T>
void Queue<T>::enqueue(T element) {
    Node* newNode = new Node(element);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

// Removes the front element of the queue and returns it
template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    Node* temp = front;
    T data = front->data;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    count--;
    return data;
}

// Returns the front element in queue without removing it
template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;
}

// Checks if the queue is empty
template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

// Returns the total number of elements present in the queue
template <typename T>
int Queue<T>::size() const {
    return count;
}
