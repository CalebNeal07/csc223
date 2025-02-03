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

string render_list(Node*);
string render_list_backward(Node*);
string render_backward_worker(Node*, string="");
string render_pretty(Node*, string (*)(Node*));