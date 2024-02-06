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

void display(Tree *root) {
    if (root == nullptr) {
        return;
    }

    // Display data of the current node
    cout << root->data << " ";

    // Recursively display the left and right subtrees
    
    display(root->left);
    
    display(root->right);
}

int main() {
    Tree *root;
    root = create();

    cout << "Tree elements: ";
    display(root);

    return 0;
}
