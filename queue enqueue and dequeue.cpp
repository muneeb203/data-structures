#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
    Node(int a) : id(a), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        Node* newnode = new Node(val);
        if (rear == nullptr) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Can't dequeue, queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int Front() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->id;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    char see;
    int x;
    do {
        cout << "Tell the operation you want to perform" << endl;
        cout << "1. Enqueue data item (+)" << endl;
        cout << "2. Dequeue data item (-)" << endl;
        cout << "3. Report whether the queue is empty (E)" << endl;
        cout << "4. Exit the program (Q)" << endl;

        cin >> see;
        if (see == '+') {
            cin >> x;
            q.enqueue(x);
        } else if (see == '-') {
            q.dequeue();
        } else if (see == 'E') {
            cout << "Queue is " << (q.isEmpty() ? "empty" : "not empty") << endl;
        } else if (see == 'Q') {
            cout << "Program Terminated" << endl;
            break;
        }
    } while (1);
}
