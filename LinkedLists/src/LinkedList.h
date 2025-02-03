using namespace std;

struct Node {
    int cargo;
    Node* next;

    // Constructors
    Node();
    Node(int);
    Node(int, Node*);
};
