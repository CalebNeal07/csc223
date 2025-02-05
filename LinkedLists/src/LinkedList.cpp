#include "LinkedList.h"

using namespace std;

template <class T>
Node<T>::Node(T cargo) {
    this->cargo = cargo;
    next = nullptr;
}

template <class T>
Node<T>::Node(T cargo, Node<T>* next) {
    this->cargo = cargo;
    this->next = next;
}

string render_list(Node<int> *list, string seperator) {
    Node<int>* node = list;
    string s = "";
    while (node != nullptr) {
        s += node->to_string();
        node = node->next;
        if (node != nullptr)
           s += seperator;
    }
    return s;
}

string render_list_backward(Node<int>* list, string seperator) {
    return render_backward_worker(list, seperator, "");
}

string render_backward_worker(Node<int> *list, string seperator, string s) {
    if (list == nullptr) return "";
    Node<int>* head = list;
    Node<int>* tail = list->next;

    s = render_backward_worker(tail, seperator, s) + s;
    if (head->next != nullptr)
        s += seperator;
    s += head->to_string();

    return s;
}

string render_pretty(Node<int>* list, string (*list_renderer)(Node<int>*, string)) {
    return "(" + list_renderer(list, ", ") + ")";
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

template <class T>
void LinkedList<T>::insert_in_front(T cargo) {
    Node<T>* front = new Node<T>(cargo, head);
    head = front;
    num_nodes++;
}
