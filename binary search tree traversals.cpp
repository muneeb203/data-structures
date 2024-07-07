#include <iostream>
#include <queue>

using namespace std;

struct Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            Node* newNode = new Node(value);
            return;
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        }
        else if (value > root->data) {
            root->right = insert(root->right, value);
        }
        return root;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNodeRecursive(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->data) {
            root->left = deleteNodeRecursive(root->left, value);
        }
        else if (value > root->data) {
            root->right = deleteNodeRecursive(root->right, value);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNodeRecursive(root->right, temp->data);
        }
        return root;
    }

    void inOrderTraversalRecursive(Node* root) {
        if (root != nullptr) {
            inOrderTraversalRecursive(root->left);
            cout << root->data << " ";
            inOrderTraversalRecursive(root->right);
        }
    }

    void preOrderTraversalRecursive(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrderTraversalRecursive(root->left);
            preOrderTraversalRecursive(root->right);
        }
    }

    void postOrderTraversalRecursive(Node* root) {
        if (root != nullptr) {
            postOrderTraversalRecursive(root->left);
            postOrderTraversalRecursive(root->right);
            cout << root->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = deleteNodeRecursive(root, value);
    }

    void breadthFirstTraversal() {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    void inOrderTraversal() {
        inOrderTraversalRecursive(root);
        cout << endl;
    }

    void preOrderTraversal() {
        preOrderTraversalRecursive(root);
        cout << endl;
    }

    void postOrderTraversal() {
        postOrderTraversalRecursive(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Breadth-First Traversal: ";
    tree.breadthFirstTraversal();
    cout << endl;

    cout << "In-Order Traversal: ";
    tree.inOrderTraversal();

    cout << "Pre-Order Traversal: ";
    tree.preOrderTraversal();

    cout << "Post-Order Traversal: ";
    tree.postOrderTraversal();

    tree.remove(30);

    cout << "In-Order Traversal after Deletion: ";
    tree.inOrderTraversal();

    return 0;
}