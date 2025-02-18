# Doubly Linked Lists: An In-Depth Look

## Introduction

* What is a linked list?
    * A linear collection of data elements, called nodes, each pointing to the next element.
* Why doubly linked lists?
    * Allow traversal in both directions (forward and backward).
    * More flexible than singly linked lists for certain operations.

<img width="780" alt="doubly-linked-list-created" src="https://github.com/user-attachments/assets/241414ff-6771-4470-b7ba-e38fdbefda48" />

## Structure of a Doubly Linked List

* **Node:**
    * `data`: Stores the actual data (can be any data type).
    * `next`: Pointer to the next node in the list.
    * `prev`: Pointer to the previous node in the list.
* **DoublyLinkedList Class:**
    * `head`: Pointer to the first node.
    * `tail` (Optional): Pointer to the last node (for optimized tail operations).
    * `length`: Keeps track of the number of nodes.

```cpp
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail; // Optional
    int length;

public:
    // ... (Methods: push, pop, insert, delete, etc.)
};
```

## Operations on Doubly Linked Lists

 -  Insertion:
     -  At the beginning (push): O(1)
     -  At the end: O(1) (if tail pointer is maintained) or O(n)
     -  At a specific position: O(n)
 -  Deletion:
     -  From the beginning (pop): O(1)
     -  From the end: O(1) (if tail pointer is maintained) or O(n)
     -  At a specific position: O(n)
 -  Traversal:
     -  Forward: O(n)
     -  Backward: O(n)
 -  Search: O(n)

## Use Case: Undo/Redo Functionality

 - Concept: Doubly linked lists are an excellent choice for implementing undo/redo functionality in applications like text editors, image editors, or web browsers. 
 - Implementation:
     -  Each node in the list represents an action performed by the user.
     -  The data field of the node stores the action itself (e.g., "insert text", "delete image", "change color").
     -  The next pointer points to the next action in the sequence (redo).
     -  The prev pointer points to the previous action (undo).
     -  A "current" pointer keeps track of the current state.
 -  Undo:
     -  Move the "current" pointer one step back (current = current->prev).
     -  Revert the action represented by the node pointed to by the new "current" pointer.
 -  Redo:
     -  Move the "current" pointer one step forward (current = current->next).
     -  Apply the action represented by the node pointed to by the new "current" pointer.
 -  Example:
     -  User types "Hello". (Node 1)
     -  User types "World". (Node 2)
     -  User presses Undo. (current -> Node 1)
     -  "World" is removed.
     -  User presses Redo. (current -> Node 2)
     -  "World" is added back.

## Advantages for Undo/Redo

 -  Efficient Undo/Redo: Moving between actions is very fast (O(1)).
 -  Easy to Add/Remove Actions: Inserting and deleting nodes (actions) is efficient.
 -  Clear History: The list maintains a clear history of actions.

## Disadvantages

 -  Memory Usage: Doubly linked lists use more memory than singly linked lists due to the prev pointer.
 -  Random Access: Accessing a specific node by index is O(n).


#### References
[https://en.wikipedia.org/wiki/Doubly_linked_list](https://en.wikipedia.org/wiki/Doubly_linked_list)  
[https://www.programiz.com/dsa/doubly-linked-list](https://www.programiz.com/dsa/doubly-linked-list)


