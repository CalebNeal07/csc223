template <class T>
class DoublyLinkedList {
    struct Node {
        T val;
        Node* next;
        Node* prev;

        Node(T val) : val(val), next(nullptr), prev(nullptr) {}
        Node(T val, Node* next) : val(val), next(next), prev(nullptr) {}
        Node(T val, Node* next, Node* prev) : val(val), next(next), prev(prev) {}

        string to_string() const { // This will cause an error unless T is a type that can be converted to string, such as std::string or char*
            return std::to_string(val); // Corrected this line, assuming you want a string representation of val
        }
    };

    unsigned int length;
    Node* head;

public:
    // Constructors
    DoublyLinkedList() : length(0), head(nullptr) {}

    // Methods
    void push(T val) {
        Node* new_node = new Node(val, head); // Allocate dynamically
        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
        length++;
    }

    T pop() {
        if (head == nullptr) {
            throw std::runtime_error("Cannot pop from an empty list."); // Or return a default value, depending on your needs.
        }

        T value = head->val;  // Store the value to return
        Node* temp = head;     // Store the node to delete

        head = head->next;     // Move the head

        if (head != nullptr) { // Update prev if the list is not now empty
            head->prev = nullptr;
        }

        delete temp;         // Delete the old head node
        length--;            // Decrement the length

        return value;
    }

    ~DoublyLinkedList() { // Destructor to prevent memory leaks
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    string to_string() { // This will cause an error unless T is a type that can be converted to string, such as std::string or char*
        string s = "";
        Node* current = head;
        while (current->next != nullptr) { // Fixed the loop condition
            s += std::to_string(current->val); // Corrected this line, assuming you want a string representation of val
            s += " <-> ";
            current = current->next;
        }
        s += std::to_string(current->val);
        return s;
    }
};