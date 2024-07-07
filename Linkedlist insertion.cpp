
#include <iostream>
using namespace std;
struct Node {
    int ID;
    string comment;
    bool label;
    Node* next;

    Node(int a, string b, bool c) {
        ID = a;
        comment = b;
        label = c;
        next = nullptr;
    }

};


class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }
    void insertAtStart(int a, string b, bool c) {
        Node* newNode = new Node(a, b, c);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int a, string b, bool c)
    {
        Node* newNode = new Node(a, b, c);
        if (!head) {
            head = newNode;
        }
        Node* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newNode;

    }

};
int main() {
    LinkedList a;

    // Insert nodes at the start
    a.insertAtStart(1, "Comment A", true);
    a.insertAtStart(2, "Comment B", false);
    a.insertAtStart(3, "Comment C", true);

    // Insert nodes at the end
    a.insertAtEnd(4, "Comment D", false);
    a.insertAtEnd(5, "Comment E", true);


    // Search for nodes by ID
  //  a.searchByID(3);

    // Display the sorted list
    Node* current = a.head;
    while (current) {
        cout << "ID: " << current->ID << ", Comment: " << current->comment << ", Label: " << (current->label ? "True" : "False") << endl;
        current = current->next;
    }

    return 0;
}
