#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* front; // Front of the queue
    Node* rear; // Rear of the queue
    int count; // Number of elements in the queue

public:
    Queue(); // Constructor
    ~Queue(); // Destructor

    void enqueue(T element); // Inserts a new element at the rear
    T dequeue(); // Removes the front element and returns it
    T peek() const; // Returns the front element without removing it
    bool isEmpty() const; // Checks if the queue is empty
    int size() const; // Returns the total number of elements in the queue
};


#include "Queue.tpp" // Implementation file

#endif // QUEUE_H
