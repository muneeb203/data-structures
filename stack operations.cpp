#include<iostream>
using namespace std;


class Stack {
private:
    static const int maxsize = 100;
    int arr[maxsize];
    int top;
public:
    Stack() {
        top = -1;

    }

    void push(int add) {
        top++;
        arr[top] = add;
    }

    void pop(){
            cout<<arr[top]<<endl;
            top--;
    }

    int peek() {
        return arr[top];
    }
    bool isEmpty() {
        if (top+1) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull() {
        
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