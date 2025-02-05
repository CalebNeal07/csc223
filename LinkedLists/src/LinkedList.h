using namespace std;

#include <string>

template <class T = int>
struct Node {
    T cargo;
    Node<T>* next;

    // Constructors
    Node(T val) : cargo(val) {}
    Node(T val, Node<T>* next) : cargo(val) 

    // Methods
    template<typename U = T, typename enable_if<is_same<U, int>::value, int>::type = 0>
    string to_string() {

        return std::to_string(this->cargo);
    }
};

template <class T = int>
class LinkedList {
    int num_nodes;
    Node<T>* head;

public:
    LinkedList() {
        num_nodes = 0;
        head = nullptr;
    }
    void insert_in_front(T);
    
    template<typename U = T, typename enable_if<is_same<U, int>::value, int>::type = 0>
    string to_string() {
        if (num_nodes == 0) {
            return "Empty list";
        }

        return render_list(head, " -> ");
    }

};

string render_list(Node<int>*, string=", ");
string render_list_backward(Node<int>*, string=", ");
string render_backward_worker(Node<int>*, string, string="");
string render_pretty(Node<int>*, string (*)(Node<int>*, string));
Node<int>* remove_second(Node<int>*);