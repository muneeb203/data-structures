#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            return '\0'; 
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isBalancedExpression(const string& expression) {
    Stack parenthesisStack;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            parenthesisStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (parenthesisStack.isEmpty()) {
                return false; 
            }

            char top = parenthesisStack.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false; 
            }
        }
    }

    return parenthesisStack.isEmpty();
}

int main() {
    string expression1 = "{[()]}}";
    string expression2 = "{ 3 + ( 5 * 4 ) / (2 * 3)] + [ (2 * 2 + (9 * 1) ] }";

    if (isBalancedExpression(expression1)) {
        cout << "Expression 1 is balanced." << endl;
    }
    else {
        cout << "Expression 1 is not balanced." << endl;
    }

    if (isBalancedExpression(expression2)) {
        cout << "Expression 2 is balanced." << endl;
    }
    else {
        cout << "Expression 2 is not balanced." << endl;
    }

    return 0;
}
