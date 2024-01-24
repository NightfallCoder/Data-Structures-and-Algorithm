#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
    vector<int>arr;
    public:
    void push(int num){
        arr.push_back(num);
        cout<<"Pushed element"<<num<<endl;
    }
    void pop(){
        if(arr.empty()){
            cout<<"Stack is empty..";
        }
        else{
            int poppedElement= arr.back();
            arr.pop_back();
            cout<<"Popped element: "<<poppedElement<<endl;
        }
    }
    int peek() const {
        if (arr.empty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Assuming -1 as an indication of an empty stack, modify as needed
        } else {
            return arr.back();
        }
    }
    void display(){
        if(arr.empty()){
            cout<<"Stack is empty";
        }
        else{
            cout<<"stack element:"<<endl;
            for(int i:arr){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
  Stack stack;
    int choice, num;

    do {
        cout << "Menu:\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n.Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> num;
                stack.push(num);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
               cout << "Top element: " << stack.peek() << endl;
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

