#include<bits/stdc++.h>
using namespace std;

#define n 5
class Queues{
    
    int *arr;
    int front;
    int rear;

public:
Queues(){
    arr=new int [n];
    front=-1;
    rear=-1;
}
void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        arr[rear]=x;
    }
    else if(((rear+1)%n)==front){
        cout<<"Queue is full";
    }
    else{
        rear=(rear+1)%n;
        arr[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty.";
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
    cout<<arr[front];
    front=(front+1)%n;
    

    }
}
void display(){
    int i=front;
    if(front==-1 && rear==-1){
        cout<<"Queue is empty.";
    }
    else{
        cout<<"Queue is: ";
        while(i!=rear){
            cout<<arr[i];
            i=(i+1)%n;
        }
        cout<<arr[rear];
    }
}
int peek(){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty";
    }
    
        return arr[front];
    
}


};
int main(){
    Queues q;
    
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
                cout << "Peek: " << q.peek() << endl;
                break;
           
            case 6:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 5);

    return 0;
}
