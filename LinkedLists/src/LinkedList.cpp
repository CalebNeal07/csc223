#include "LinkedList.h"

using namespace std;

#include <stdexcept>

Node::Node() {
    cargo = 0;
    next = nullptr;
}

Node::Node(int cargo) {
    this->cargo = cargo;
    next = nullptr;
}

Node::Node(int cargo, Node* next) {
    this->cargo = cargo;
    this->next = next;
}

string Node::to_string() {
        return std::to_string(this->cargo);
}

string render_list(Node *list, string seperator) {
    Node* node = list;
    string s = "";
    while (node != nullptr) {
        s += node->to_string();
        node = node->next;
        if (node != nullptr)
           s += seperator;
    }
    return s;
}

string render_list_backward(Node* list, string seperator) {
    return render_backward_worker(list, seperator, "");
}

string render_backward_worker(Node *list, string seperator, string s) {
    if (list == nullptr) return "";
    Node* head = list;
    Node* tail = list->next;

    s = render_backward_worker(tail, seperator, s) + s;
    if (head->next != nullptr)
        s += seperator;
    s += head->to_string();

    return s;
}

string render_pretty(Node* list, string (*list_renderer)(Node*, string)) {
    return "(" + list_renderer(list, ", ") + ")";
}

Node* remove_second(Node* list) {
    Node* first = list;
    Node* second = list->next;

    // make the first node point to the third
    first->next = second->next;

    // remove the second node from the list and return a pointer to it
    second->next = nullptr;
    return second;
}

void LinkedList::insert_in_front(int cargo) {
    Node* front = new Node(cargo, head);
    head = front;
    num_nodes++;
}

int LinkedList::remove_from_front() {
    if (head == nullptr)
        throw runtime_error("Can't remove from empty list!");
    int cargo = head->cargo;
    Node* front = head;
    head = head->next;
    delete front;
    num_nodes--;
    return cargo;
}

string LinkedList::to_string() {
    if (num_nodes == 0) {
        return "Empty list";
    }

    return render_list(head, " -> ");
}
