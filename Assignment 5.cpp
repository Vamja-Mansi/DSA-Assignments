//Assignment 5
//Binary Search Tree

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}
TreeNode* findMin(TreeNode* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) return root;

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}
void displayLevelWise(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int nodeCount = q.size();
        while (nodeCount > 0) {
            TreeNode* node = q.front();
            cout << node->value << " ";
            q.pop();

            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);

            nodeCount--;
        }
        cout << endl; // New level
    }
}
int main() {
    TreeNode* root = NULL;

    // Insert nodes
    
    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 80);
    root = insert(root, 60); 
	root = insert(root, 90);
	root = insert(root, 50);

    cout << "Level order traversal of the BST:" << endl;
    displayLevelWise(root);

    cout << "Deleting node 20:" << endl;
    root = deleteNode(root, 20);
    displayLevelWise(root);

    cout << "Deleting node 30:" << endl;
    root = deleteNode(root, 30);
    displayLevelWise(root);

    cout << "Deleting node 50:" << endl;
    root = deleteNode(root, 50);
    displayLevelWise(root);

    return 0;
}
