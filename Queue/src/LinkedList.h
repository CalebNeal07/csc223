#include <string>
using namespace std;


template <class T>
struct Node
{
    T cargo;
    Node<T>* next;

    Node(T cargo, Node<T>* next)
    {
        this->cargo = cargo;
        this->next = next;
    }
};


template <class T>
class LinkedList
{
    Node<T>* head;

public:
    LinkedList() {
        head = nullptr;
    }

    int length() {
        if (head == nullptr) return 0;
        if (head->next == nullptr) return 1;
        int num_nodes = 0;
        for (Node<T>* np = head; np != nullptr; np = np->next, num_nodes++);
        return num_nodes;
    }

    void insert_at_front(T cargo) {
        Node<T>* front = new Node<T>(cargo, head);
        head = front;
    }

    T remove_from_front() {
        if (head == nullptr)
            throw runtime_error("Can't remove from and empty list!");
        T cargo = head->cargo;
        Node<T>* front = head;
        head = head->next;
        delete front;
        return cargo;
    }

    void insert_at_end(T cargo) {
        if (head == nullptr)
            insert_at_front(cargo);
        else {
            Node<T>* node = new Node<T>(cargo, nullptr);
            if (head->next == nullptr) {
                head->next = node;
            } else {
               // set pointer to last node
               Node<T>* last = head;
               while (last->next != nullptr) {
                   last = last->next;
               }
               // attach the node
               last->next = node;
            }
        }
    }

    T remove_from_end() {
        if (head == nullptr)
            throw runtime_error("Can't remove from and empty list!");
        if (head->next == nullptr)
            return remove_from_front();
        Node<T>* last = head->next;
        Node<T>* next_to_last = head;
        while (last->next != nullptr) {
            next_to_last = last;
            last = last->next;
        }
        T cargo = last->cargo;
        next_to_last->next = nullptr;
        delete last;
        return cargo;
    }

    T get_item_at(int pos) {
        if (pos > length())
            throw runtime_error("Not that many items in list!");
        Node<T>* node = head;
        for (int i = 1; i < pos; i++)
            node = node->next;
        return node->cargo;
    }

    void insert_item_at(T cargo, int pos) {
        if (pos > length() + 1)
            throw runtime_error("Can't insert past the end of the list!");
        if (pos == 0)
            insert_at_front(cargo);
        else if (pos == length())
            insert_at_end(cargo);
        else {
            Node<T>* before = head;
            Node<T>* after = head->next;
            for (int i = 1; i < pos; i++) {
                before = after;
                after = after->next;
            }
            Node<T>* node = new Node<T>(cargo, after);
            before->next = node;
        }
    }

    T remove_item_at(int pos) {
        if (pos < 1 || pos > length())
            throw runtime_error("Invalid item number!");
        if (pos == 1)
            return remove_from_front();
        if (pos == length())
            return remove_from_end();
        Node<T>* prev = head;
        Node<T>* goodbyenode = head->next;
        for (int i = 2; i < pos; i++) {
            prev = goodbyenode;
            goodbyenode = goodbyenode->next;
        }
        T cargo = goodbyenode->cargo;
        prev->next = goodbyenode->next;
        delete goodbyenode;
        return cargo;
    }
};
