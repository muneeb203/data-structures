#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class SinglyCircularLinkedList {
private:
    Node* head;

public:
    SinglyCircularLinkedList() : head(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void prepend(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAfter(int prevData, int data) {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        do {
            if (temp->data == prevData) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node with data " << prevData << " not found" << endl;
    }

    void deleteFirst() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
    }

    void deleteLast() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node* temp = head;
            Node* prev = nullptr;
            do {
                prev = temp;
                temp = temp->next;
            } while (temp->next != head);
            prev->next = head;
            delete temp;
        }
    }

    void deleteSpecific(int data) {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == data) {
            deleteFirst();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == data) {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node with data " << data << " not found" << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data;
            if (temp->next != head) {
                cout << " -> ";
            }
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~SinglyCircularLinkedList() {
        while (!isEmpty()) {
            deleteFirst();
        }
    }
};

int main() {
    SinglyCircularLinkedList linkedList;

    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);

    cout << "Original List:" << endl;
    linkedList.display();

    linkedList.prepend(0);
    cout << "List after prepending 0:" << endl;
    linkedList.display();

    linkedList.insertAfter(2, 4);
    cout << "List after inserting 4 after 2:" << endl;
    linkedList.display();

    linkedList.deleteFirst();
    cout << "List after deleting the first node:" << endl;
    linkedList.display();

    linkedList.deleteLast();
    cout << "List after deleting the last node:" << endl;
    linkedList.display();

    linkedList.deleteSpecific(2);
    cout << "List after deleting the node with data 2:" << endl;
    linkedList.display();

    return 0;
}
