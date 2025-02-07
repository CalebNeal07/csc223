#include "LinkedList.h"

using namespace std;

Node::Node(int cargo) {
    this->cargo = cargo;
    next = nullptr;
}

template <class T>
Node<T>::Node(T cargo, Node<T>* next) {
    this->cargo = cargo;
    this->next = next;
}

string Node::to_string() {
        return std::to_string(this->cargo);
}

string render_list(Node *list) {
    Node* node = list;
    string s = "";
    while (node != nullptr) {
        s += node->to_string();
        node = node->next;
        if (node != nullptr)
           s += ", ";
    }
    return s;
}

string render_list_backward(Node* list) {
    return render_backward_worker(list, "");
}

string render_backward_worker(Node *list, string s) {
    if (list == nullptr) return "";
    Node<int>* head = list;
    Node<int>* tail = list->next;

    s = render_backward_worker(tail, s) + s;
    if (head->next != nullptr)
        s += ", ";
    s += head->to_string();

    return s;
}

string render_pretty(Node* list, string (*list_renderer)(Node*)) {
    return "(" + list_renderer(list) + ")";
}

Node<int>* remove_second(Node<int>* list) {
    Node<int>* first = list;
    Node<int>* second = list->next;

    // make the first node point to the third
    first->next = second->next;

    // remove the second node from the list and return a pointer to it
    second->next = nullptr;
    return second;
}
