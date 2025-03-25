#include "LinkedList.h"
#include <utility>  // for std::pair

template <class T>
class PriorityQueue {
private:
    // Store items as pairs of (priority, value)
    LinkedList<std::pair<int, T>> list;

public:
    // Constructor
    PriorityQueue() {}

    // Check if the queue is empty
    bool isEmpty() {
        return list.length() == 0;
    }

    // Get the number of items in the queue
    int size() {
        return list.length();
    }

    // Insert an item with the given priority
    // Lower priority values indicate higher priority
    void enqueue(T item, int priority) {
        // Create a pair of priority and item
        std::pair<int, T> entry = std::make_pair(priority, item);
        
        // If the queue is empty, just insert at the front
        if (isEmpty()) {
            list.insert_at_front(entry);
            return;
        }
        
        // Find the correct position to insert based on priority
        int position = 1;
        bool inserted = false;
        
        for (int i = 1; i <= list.length(); i++) {
            std::pair<int, T> current = list.get_item_at(i);
            if (priority < current.first) {
                // Found a position where the new item has higher priority
                list.insert_item_at(entry, i);
                inserted = true;
                break;
            }
            position++;
        }
        
        // If no position was found, insert at the end
        if (!inserted) {
            list.insert_at_end(entry);
        }
    }

    // Remove and return the highest priority item
    T dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot dequeue from an empty priority queue");
        }
        
        // The highest priority item is at the front of the list
        std::pair<int, T> entry = list.remove_from_front();
        return entry.second;
    }

    // Peek at the highest priority item without removing it
    T peek() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot peek at an empty priority queue");
        }
        
        // The highest priority item is at the front of the list
        std::pair<int, T> entry = list.get_item_at(1);
        return entry.second;
    }
    
    // Get the priority of the highest priority item
    int peekPriority() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot peek at an empty priority queue");
        }
        
        std::pair<int, T> entry = list.get_item_at(1);
        return entry.first;
    }
};

