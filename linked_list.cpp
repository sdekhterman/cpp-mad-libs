#include <iostream>

// Node structure
struct Node {
    int data;     // store an integer value assioated with node
    Node* next;   // point to next node in the chain
    // this is a constructor, i.e. instructions for start up that tell the class how what to do when a new instance of this class is created 
    // the class has an input arguement of val [Node(int val)] which is assigned in data an initializer list [: data(val), next(nullptr)] 
    // with the body of the constructor otherwise being empty [ {} ]
    Node(int val) : data(val), next(nullptr) {} 
};

// Linked list class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Insert at the end
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Insert at the beginning
    void prepend(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Delete a node with a specific value
    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data != val) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Print the list
    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.prepend(0);
    list.printList(); // Output: 0 1 2
    list.deleteNode(1);
    list.printList(); // Output: 0 2
    return 0;
}