#include<bits/stdc++.h>
using namespace std;

class Tree {
public:
    Tree *left;
    char data;
    Tree *right;
public:
    Tree(Tree *left1, char data1, Tree *right1) {
        left = left1;
        data = data1;
        right = right1;
    }
public:
    Tree(char data1) {
        left = nullptr;
        data = data1;
        right = nullptr;
    }
};

// Forward declaration of the height function
int height(Tree* root);

Tree* create() {
    char x;

    cout << "Enter data (1 for no node): " << endl;
    cin >> x;
    Tree *newNode = new Tree(x);
    if (x == '1')
        return nullptr; // Return nullptr for leaf nodes
    
    cout << "Enter left child data for " << x << ": ";
    newNode->left = create();

    cout << "Enter right child data for " << x << ": ";
    newNode->right = create();

    return newNode;
}

void printLevel(Tree* root, int level) {
    if (root == NULL)
        return;
    if (level == 0) {
        cout << root->data << " ";
    }
    else if (level > 0) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void printLevelOrder(Tree* root) {
    int h = height(root);
    for (int i = 0; i <= h; i++)
        printLevel(root, i);
}

int height(Tree* root) {
    if (root == NULL) {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight) {
        return (lheight + 1);
    }
    return (rheight + 1);
}

int main() {
    Tree *root;
    root = create();

    cout << "Tree elements: ";
    printLevelOrder(root);

    return 0;
}
