#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    int height;
    
    // Constructors
    Node(int data1, Node *left1, Node *right1) {
        data = data1;
        left = left1;
        right = right1;
        height = 1; // Initialize height to 1
    }
    
    Node(int data1) {
        data = data1;
        left = NULL;
        right = NULL;
        height = 1; // Initialize height to 1
    }
};


//find height of any given tree
int getHeight(Node *n){
	if(n==NULL)return 0;
	return n->height;
}
//search node
Node *search(Node *root,int value){
	if(root!=NULL){
		if(value<root->data){
			root=search(root->left,value);
		}
		else if(value>root->data){
			root=search(root->right,value);
		}
	}
	return root;
}
//create node
Node *createNode(int data){
	Node* node= new Node(data);
	
	return node;
}
//get balance factor
int getBalanceFactor(Node *n){
if(n==NULL){
	return 0;
}
//n->left->height-n->right->height;
return getHeight(n->left)-getHeight(n->right);
}
//rightRotation(y=root node)
Node *rightRotate(Node *y){
	Node* x=y->left;
	Node *T2=x->right;
	
	
	x->right=y;
	y->left=T2;
	
	y->height=max(getHeight(y->right),getHeight(y->left))+1;
	x->height=max(getHeight(x->right),getHeight(x->left))+1;
	return x;
}
//leftRotation(x=root node)
Node *leftRotate(Node *x){
	Node* y=x->right;
	Node *T2=y->left;
	
	
	y->left=x;
	x->right=T2;
	
	y->height=max(getHeight(y->right),getHeight(y->left))+1;
	x->height=max(getHeight(x->right),getHeight(x->left))+1;
	return y;
}
Node *insert(Node *node,int data){
	if(node==NULL)
		return createNode(data);
	
	if(data<node->data)
		node->left=insert(node->left,data);
	
	else if(data>node->data)
		node->right=insert(node->right,data);
		

	
	node->height=1+max(getHeight(node->left),getHeight(node->right));//update height
	int bf=getBalanceFactor(node);//balance factor
	
	//if unbalanced:4cases 
	//1.LL Rotation
	if(bf>1 && data<node->left->data){
		return rightRotate(node);
	}
	//2.RR Rotation
	if(bf<-1 && data>node->right->data){
		return leftRotate(node);
	}
	//3.LR Rotation
	if(bf>1 && data>node->left->data){
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	//4.RL Rotation
	if(bf<-1 && data<node->right->data){
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
void preOrder(Node *root){
	if(root!=NULL){
		cout<<root->data<<" ";
		cout<<endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main(){

int value,option;
    Node *root = NULL;

//    cout << "Number of elements you want to add: ";
//    cin >> size;
//
//    for (int i = 0; i < size; i++) {
//        cout << "Enter value: ";
//        cin >> value;
//        root = insert(root, value);
//    }
////	root=insert(root,1);
//	root=insert(root,2);
//	root=insert(root,4);
//	root=insert(root,5);
//	root=insert(root,6);
//	root=insert(root,3);
    while(1){
    	cout<<"1.INSERT"<<endl;
    	cout<<"2.PREORDER DISPLAY"<<endl;
    	cout<<"3.EXIT"<<endl;
    	cout<<"SELECT: ";
    	cin>>option;
    	switch(option){
    		case 1:
    			cout<<"Enter the value to be inserted: ";
    			cin>>value;
    			if(search(root,value)==NULL)
    			root=insert(root,value);
    			else
    			cout<<"Duplicate value not allowed!!";
    			break;
    			
    			case 2:
    				if(root==NULL){
    					cout<<"Tree is empty";
    					continue;
								}
								cout<<"Tree is: "<<endl;
								preOrder(root);
								break;
								
								case 3:
									exit(1);
									default:
										cout<<"Wrong option"<<endl;
					}
				}
    return 0;
}