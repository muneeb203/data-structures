#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() : head(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else {
            Node* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void prepend(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else {
            Node* first = head;
            Node* last = head->prev;
            newNode->next = first;
            first->prev = newNode;
            newNode->prev = last;
            last->next = newNode;
            head = newNode;
        }
    }

    void insertAfter(int prevData, int data) {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        do {
            if (current->data == prevData) {
                newNode->next = current->next;
                current->next->prev = newNode;
                newNode->prev = current;
                current->next = newNode;
                return;
            }
            current = current->next;
        } while (current != head);
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
            Node* first = head;
            Node* last = head->prev;
            head = first->next;
            head->prev = last;
            last->next = head;
            delete first;
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
            Node* first = head;
            Node* last = head->prev;
            last->prev->next = first;
            first->prev = last->prev;
            delete last;
        }
    }

    void deleteSpecific(int data) {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        do {
            if (current->data == data) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Node with data " << data << " not found" << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    ~DoublyCircularLinkedList() {
        while (!isEmpty()) {
            deleteFirst();
        }
    }
};

int main() {
    DoublyCircularLinkedList linkedList;

    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);

    cout << "Original List:" << endl;
    linkedList.display();

    linkedList.prepend(0);
    cout << "List after prepend:" << endl;
    linkedList.display();

    linkedList.insertAfter(2, 4);
    cout << "List after insertion after 2:" << endl;
    linkedList.display();

    linkedList.deleteFirst();
    cout << "List after deleting the first node:" << endl;
    linkedList.display();

    linkedList.deleteLast();
    cout << "List after deleting the last node:" << endl;
    linkedList.display();

    linkedList.deleteSpecific(2);
    cout << "List after deleting node with data 2:" << endl;
    linkedList.display();

    return 0;
}
