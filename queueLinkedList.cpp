#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    public:
    node(int data1,node* next1){
        data=data1;
        next=next1;
    }
    node(int data1){
        data=data1;
        next=nullptr;
    }
};
class Queue{
    node* front;
    node* back;

    public:
    Queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* newnode= new node(x);
        if(front==NULL){
            front=back=newnode;
            return;
        }
        back->next=newnode;
        back=newnode;
    }
    void pop(){
        if(front==NULL){
            cout<<"UNDERFLOW!!";
            return;
        }
        node* temp=front;
        front=front->next;
        delete temp;
    }
    int peek(){
        if(front==NULL){
            cout<<"No element in queue";
            return -1;
        } 
        return front->data;
    }
    bool empty(){
         if(front==NULL){
            
            return true;
        }
        return false;
    }
    void display(){
         if(front==NULL && back==0){
            cout<<"Queue is empty";
            return;
        }
        node* temp=front;
        while(temp!=0){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;

int ch, num;

    do {
        cout << "1) Insert element to queue" << endl;
        cout << "2) Delete element from queue" << endl;
        cout << "3) Display all the elements of queue" << endl;
        cout << "4) Peek" << endl;
        cout << "5) Empty?" << endl;
        cout << "6) Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> num;
                q.push(num);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Peek: " << q.peek() << endl;
                break;
            case 5:
                cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 6:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 6);

    return 0;
}

