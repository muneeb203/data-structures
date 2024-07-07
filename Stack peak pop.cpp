#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        data = 0;
        next = nullptr;
    }
};
class Stack {
public:
    Node* top;
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        Node* a = new Node(data);
        if (!top) {
            top = a;
        }
        else {
            Node* current = top;
            while (current->next)
                Node* current = top;


            current->next = a;
        }
    }
    

    void pop() {
        /*  cout << arr[top] << endl;
          top--;*/
        Node* current = top;
        while (current->next) {
            
        }
        current--;
    }

   Node* peek() {
        return top;
      
    }
    bool isEmpty() {
        if (!top) {
            return true;
     }
    }
    bool isFull() {
        return true;
    }
};







int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element: " << myStack.peek() << endl;

    myStack.pop();
    cout << "Top element after pop: " << myStack.peek() << endl;

    myStack.pop();
    myStack.pop(); // Pop the remaining elements

    if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}