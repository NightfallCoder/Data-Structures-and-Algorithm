#include<bits/stdc++.h>
using namespace std;

const int N = 7; // Size of the stack

int stacks[N];
int top = -1;
void push(int num){
if(top==N-1)//top full
{
    cout<<"Overflow";
}
else{
    top++;
    stacks[top]=num;
    cout<<"Pushed Element: "<<num<<endl;
}
}
void pop(){
    int num;
    if(top==-1){
        cout<<"Underflow";
    }
    else{
        num=stacks[top];
        top--;
        cout<<"Popped Element: "<<num<<endl;
    }
}
void peek(){
    if(top==-1){
        cout<<"Stack is element";
    }
    else{
        cout<<"Topped element: "<<stacks[top]<<endl;
    }
}
void display(){
    int i;
    cout<<"Stack elements"<<endl;
    for(i=0;i<=top;i++){
        cout<<stacks[i]<<" ";
    }
    cout<<endl;
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
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
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



