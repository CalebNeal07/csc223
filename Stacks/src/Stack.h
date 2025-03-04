#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 128
#include <stdexcept>

template <class T>
class Stack {
    int top_item;
    T items[MAX_SIZE];

public:
    Stack() {
        top_item = -1;
    }

    void push(const T& value) {
        if (top_item >= MAX_SIZE - 1) {
            throw std::overflow_error("Stack overflow");
        }
        items[++top_item] = value;
    }

    T pop() {
        if (empty()) {
            throw std::underflow_error("Stack underflow");
        }
        return items[top_item--];
    }

    const T& top() const {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return items[top_item];
    }

    bool empty() const {
        return top_item == -1;
    }

    size_t size() const {
        return top_item + 1;
    }
};

#endif // STACK_H
