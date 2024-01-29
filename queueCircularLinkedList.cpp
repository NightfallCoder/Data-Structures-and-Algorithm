#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

public:
Node(int data1,Node* next1){
    data=data1;
    next=next1;
}
Node(int data1){
    data=data1;
    next=nullptr;
}
};

class Queue{
   
public:
Node* front;
Node* rear;
Queue(){
    front=0;
    rear=0;
}
    void enqueue(int x){
        Node* newnode= new Node(x);
        if(rear==0){
            front=rear=newnode;
            rear->next=front;
        }
        else{
            rear->next=newnode;
            rear=newnode;
            rear->next=front;
        }
    }
    void dequeue(){
        Node* temp=front;
        if(front==0 && rear==0){
            cout<<"Empty Queue"<<endl;
        }
        else if(front==rear){
            front=rear=0;
            free(temp);
        }
        else{
            front=front->next;
            rear->next=front;
            free(temp);
        }
    }
    int peek(){
        if(front==0 && rear==0){
            cout<<"Empty"<<endl;
        }
        else{
            return front->data;
        }
    }
    void display(){
        Node* temp=front;
        if(front==0 && rear==0){
            cout<<"Empty"<<endl;
        }
        else{
            while(temp->next!=front){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        cout<<temp->data<<endl;
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
        cout << "5) Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> num;
                q.enqueue(num);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Peek: " << q.peek() <<endl;
                break;
           
            case 5:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 5);

    return 0;
}
