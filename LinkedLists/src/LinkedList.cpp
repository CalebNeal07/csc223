#include "LinkedList.h"

using namespace std;

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
    Node* head = list;
    Node* tail = list->next;

    s = render_backward_worker(tail, s) + s;
    if (head->next != nullptr)
        s += ", ";
    s += head->to_string();

    return s;
}

string render_pretty(Node* list, string (*list_renderer)(Node*)) {
    return "(" + list_renderer(list) + ")";
}