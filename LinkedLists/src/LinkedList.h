using namespace std;

#include <string>

struct Node {
    int cargo;
    Node* next;

    // Constructors
    Node();
    Node(int);
    Node(int, Node*);

    // Methods
    string to_string();
};

class LinkedList
{
    int num_nodes;
    Node* head;

public:
    LinkedList() {
        num_nodes = 0;
        head = nullptr;
    }
    void insert_in_front(int);
    string to_string();
};

string render_list(Node*, string=", ");
string render_list_backward(Node*, string=", ");
string render_backward_worker(Node*, string, string="");
string render_pretty(Node*, string (*)(Node*, string));
Node* remove_second(Node*);