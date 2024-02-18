#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;

public:
Node(int data1){
    data=data1;
    left=NULL;
    right=NULL;
}
};
Node* insertBST(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

void inOrder(Node* root){
    if(root==NULL)return;
    else{
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
Node* searchInBST(Node* root,int key){
    if(root==NULL)return NULL;
    if(root->data==key)return root;
    if(root->data>key){
    return searchInBST(root->left,key);
    }
    //data<key
    return searchInBST(root->right,key);

}
//smallest element or smallest node
int smallestElement(Node* root){
    
    if(root==NULL || root->left==NULL){
        return root->data;
    }
    else{
        return smallestElement(root->left);
    }
}
//largest element or largest node
int largestElement(Node* root){
    
    if(root==NULL || root->right==NULL){
        return root->data;
    }
    else{
        return largestElement(root->right);
    }
}

Node* largestNode(Node* root){
    //predecessor
    if(root==NULL || root->right==NULL){
        return root;
    }
    else{
        return largestNode(root->right);
    }
}
//Deleting a Node from Binary Search Tree (1.Having no children)
Node* Delete(Node* root,int val){
    if (root==NULL){
        cout<<"Value not found"<<endl;
        return root;
    }
    else if(val<root->data){
       root->left= Delete(root->left,val);
    }
    else if(val>root->data){
       root->right= Delete(root->right,val);
    }

    // if root->data==val having both left and right nodes
    else if(root->left && root->right){
        Node* temp=largestNode(root->left);
        root->data=temp->data;
        Delete(root->left,temp->data);
    }
    //if either left or right or null
    else { // Found the node to delete
        Node* temp = root;
        if (root->left == NULL) {
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            root = root->left;
            delete temp;
        } else { // Node to be deleted has two children
            Node* predecessor = largestNode(root->left);
            root->data = predecessor->data;
            root->left = Delete(root->left, predecessor->data);
        }
    }
    return root;
}
//Finding height of a tree
int height(Node* root){
    if(root==NULL)return 0;
    else{
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        if(leftHeight>rightHeight){
            return leftHeight+1;
        }
        return rightHeight+1;
    }
}
//Total Number of Nodes in a Tree
int TotalNodes(Node* root){
    
    if(root==NULL)return 0;
    return TotalNodes(root->left)+TotalNodes(root->right)+1;
}
//Total number of internal nodes or non-leaf nodes in a Tree
int TotalInternalNodes(Node* root){
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)return 0;
    return TotalInternalNodes(root->left)+TotalInternalNodes(root->right)+1;
}
//Total number of external nodes or leaf nodes in a Tree
int TotalExternalNodes(Node* root){
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)return 1;
    return TotalExternalNodes(root->left)+TotalExternalNodes(root->right);
}
//Mirror Image of the Tree
Node* mirrorImage(Node* root){
    if(root!=NULL){
    
        mirrorImage(root->left);
        mirrorImage(root->right);
        Node* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    return root;
}
void display(Node *root) {
    if (root == nullptr) {
        return;
    }

    // Display data of the current node
    
   

    // Recursively display the left and right subtrees
    
    display(root->left);
     cout << root->data << " ";
    display(root->right);
    
    
}
int main(){
    int val,option,key;
     Node* root=NULL;
    do{
        cout<<"\n1.INSERT ELEMENTS"<<endl;
        cout<<"2. SEARCH ELEMENTS"<<endl;
        cout<<"3. DELETE ELEMENTS"<<endl;
        cout<<"4. DISPLAY"<<endl;
        cout<<"5. HEIGHT"<<endl;
        cout<<"6. NUMBER OF NODES"<<endl;
        cout<<"7. NUMBER OF INTERNAL NODES"<<endl;
        cout<<"8. NUMBER OF EXTERNAL NODES"<<endl;
         cout<<"9.LARGEST ELEMENT IN THE TREE"<<endl;
        cout<<"10. SMALLEST ELEMENT IN THE TREE"<<endl;
        cout<<"11.. MIRROR IMAGE OF THE TREE"<<endl;
        cout<<"12.EXIT"<<endl;
        cout<<"OPTION-->1/2/3/4/5/6/7/8/9/10/11/12: ";
        cin>>option;
    
    switch(option){
        case 1:
        cout<<"Enter value: ";
    cin>>val;
    
   
    root=insertBST(root,val);
    break;
    
    case 2:
    cout<<"Enter element to be searched: ";
    cin>>key;
    if(searchInBST(root,key)==NULL){
        cout<<"Doesn't exist!!"<<endl;
    }
    else{
        cout<<"Element exists"<<endl;
    }

    break;
    case 3:
    cout<<"Enter value to be deleted: ";
    cin>>val;
    root=Delete(root,val);
    break;

    case 4:
    cout<<"Elements--->"<<endl;
    display(root);
    break;

   case 5:
    cout << "Height of the Tree is--->" << height(root) << endl;
    break;
     
     case 6:
    cout << "Number of nodes are--->" << TotalNodes(root) << endl;
    break;
    case 7:
    cout<<"Number of internal nodes are---->"<<TotalInternalNodes(root)<<endl;
    break;

    case 8:
    cout<<"Number of external nodes are--->"<<TotalExternalNodes(root);
    break;

    case 11:
    cout<<"Mirror Image--->"<<endl;
    root=mirrorImage(root);
    display(root);
    break;

    case 9:
    cout<<"Largest Element is: "<<largestElement(root);
    break;

    case 10:
    cout<<"Smallest Element is: "<<smallestElement(root);
    break;

    }
    
   
    
    }while(option!=12);
inOrder(root);
    return 0;
}