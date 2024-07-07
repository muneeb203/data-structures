

#include <iostream>
using namespace std;
class TreeNode {
private:
    int data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int a) {
        data = a;
        left = right = NULL;
    }


    static TreeNode* arrayToBinaryTree(int arr[], int start, int end) {
        //basecase
        if (start >end)
        {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = arrayToBinaryTree(arr, start, mid-1);
        root->right = arrayToBinaryTree(arr, mid+1, end);
        return root;
       
    }

    static void inOrderTraversal(TreeNode* root)
    {
        if (root)
        {
            inOrderTraversal(root->left);
            cout << root->data;
            inOrderTraversal(root->right);

        }

    }

    static void preOrderTraversal(TreeNode* root) {
        if (root) {
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
            cout << root->data;
        }
    }
    static void postOrderTraversal(TreeNode* root) {
        if (root) {
            cout << root->data;
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
        }
    }
};
int main() {
    
    // Example array: {1, 2, 3, 4, 5}
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Convert array to binary tree
    TreeNode* root = TreeNode::arrayToBinaryTree(arr, 0, size - 1);

    // Perform traversals
    cout << "In-order traversal: ";
    TreeNode::inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    TreeNode::preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    TreeNode::postOrderTraversal(root);
    cout << endl;


    return 0;
}
