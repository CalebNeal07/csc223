#include <stdexcept>
#include <utility>  // for std::pair

template <class T>
class ArrayPriorityQueue {
private:
    // Maximum size of the array
    static const int MAX_SIZE = 100;
    
    // Array to store priority-value pairs
    std::pair<int, T> elements[MAX_SIZE];
    
    // Current number of elements in the queue
    int count;
    
    // Helper method to shift elements to make room for insertion
    void shiftRight(int position) {
        for (int i = count; i > position; i--) {
            elements[i] = elements[i - 1];
        }
    }

public:
    // Constructor
    ArrayPriorityQueue() : count(0) {}
    
    // Check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }
    
    // Check if the queue is full
    bool isFull() const {
        return count == MAX_SIZE;
    }
    
    // Get the number of items in the queue
    int size() const {
        return count;
    }
    
    // Insert an item with the given priority
    // Lower priority values indicate higher priority
    void enqueue(T item, int priority) {
        if (isFull()) {
            throw std::runtime_error("Priority queue is full");
        }
        
        // Find the correct position to insert based on priority
        int position = 0;
        while (position < count && elements[position].first <= priority) {
            position++;
        }
        
        // Shift elements to make room for the new item
        shiftRight(position);
        
        // Insert the new item
        elements[position] = std::make_pair(priority, item);
        count++;
    }
    
    // Remove and return the highest priority item
    T dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot dequeue from an empty priority queue");
        }
        
        // Get the highest priority item (at the front of the array)
        T item = elements[0].second;
        
        // Shift all elements left to fill the gap
        for (int i = 0; i < count - 1; i++) {
            elements[i] = elements[i + 1];
        }
        
        count--;
        return item;
    }
    
    // Peek at the highest priority item without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Cannot peek at an empty priority queue");
        }
        
        return elements[0].second;
    }
    
    // Get the priority of the highest priority item
    int peekPriority() const {
        if (isEmpty()) {
            throw std::runtime_error("Cannot peek at an empty priority queue");
        }
        
        return elements[0].first;
    }
    
    // Clear the queue
    void clear() {
        count = 0;
    }
    
    // Get the capacity of the queue
    int capacity() const {
        return MAX_SIZE;
    }
};
