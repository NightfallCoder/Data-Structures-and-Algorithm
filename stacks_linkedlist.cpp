#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* link;
    
    public:
    Node (int data1,Node* link1){
        data=data1;
        link=link1;
    }
    Node (int data1){
        data=data1;
        link=nullptr;
    }
};
Node* top=0;
void push(int num){
    Node* newnode=new Node(num);
    if(top==NULL){
        newnode->link=NULL;
        top=newnode;
    }
    else{
        newnode->link=top;
        top=newnode;
    }
    
}
void display(){
    Node* temp=top;
    if(top==0){
        cout<<"Stack is empty!!";
    }
    else{
        while(temp!=0){
            cout<<temp->data<<" ";
            temp=temp->link;
        }
    }
}
void peek(){
    if(top==0){
        cout<<"Stack is empty!";
    }
    else{
        cout<<top->data;
    }
}
void pop(){
    Node* temp=top;
    if(top==0){
        cout<<"Stack is empty";
    }
    else{
        cout<<top->data;
        top=top->link;
        free(temp);
    }
}
int main(){
int choice, num;

    do {
        cout << "Menu:\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n.Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> num;
                push(num);
                break;
            case 2:
            cout<<" Popped element: ";
                pop();
                break;
            case 3:
            cout<<"Element displayed: ";
                display();
                break;
            case 4:
            cout<<"Topped or Peeked element: ";
                 peek();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}



