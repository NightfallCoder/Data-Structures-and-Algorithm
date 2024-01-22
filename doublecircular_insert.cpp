#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
Node* create_doublycll(vector<int>&arr){
    int n=arr.size();
    Node* head=new Node (arr[0]);
    Node* previous=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        temp->prev=previous;
        previous->next=temp;
        previous=temp;
    }
    previous->next=head;
    return head;
}
void traverse(Node* head){
    Node* temp=head;
    
      do {
        cout <<temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
//INSERT AT THE BEG
Node* insert_at_beg(Node* head,int val){
    Node* temp=new Node(val);
   Node* tail=head;
   while(tail->next!=head){
    tail=tail->next;
   }
   tail->next=temp;
   temp->next=head;
   head->prev=temp;

   return temp;

   
}
//INSERT AT THE END
Node* insert_at_end(Node* head,int val){
    Node* newTail=new Node(val);
    Node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=newTail;
    newTail->prev=tail;
    newTail->next=head;

    return head;
}
Node* insert_before(Node* head, int val, int pos) {
    Node* current = new Node(val);
    Node* temp = head;
    int count=1;
    
     while (count < pos-1) {
        temp = temp->next;
        count++; // Increment the counter
    }

    // Insert before the found node
    current->next = temp;
    current->prev = temp->prev;

    temp->prev->next = current;
    temp->prev = current;

    return head;
}

Node* insert_after(Node* head, int val, int pos) {
    Node* current = new Node(val);
    Node* temp = head;
    int count=1;
   
     while (count < pos) {
        temp = temp->next;
        count++; // Increment the counter
    }

    // Insert after the found node
    current->prev = temp;
    current->next = temp->next;

    temp->next->prev = current;
    temp->next = current;

    return head;
}

int length_of_DCLL(Node* head){
    Node* temp=head;
    int count=1;
    while(temp->next!=head){
        temp=temp->next;
        count++;
    }
    return count;
}
int main(){
    vector<int> arr;
    int size,value,num;
    cout<<"Enter size of the element: "<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>num;
        arr.push_back(num);
    }
    Node* head= create_doublycll(arr);
    traverse(head);

    char choice;
     do {
        cout<<"\nChoose an option:"<<endl;
        cout<<"1. Insert at the beginning\n";
        cout<<"2 Insert at the end\n";
        cout<<"3 Insert after the given position\n";
        cout<<"4 Insert before the given position\n";
        cout<<" Enter your choice 1/2/3/4: \n";
        cin >> choice;

        
            int val,pos;
            switch(choice){
                case '1':
                     cout << "Enter value to insert: ";
                     cin >> val;
                    cout << "Inserting node....." << endl;
                    head = insert_at_beg(head, val);
                    
                break;
                 case '2':
                     cout << "Enter value to insert: ";
                     cin >> val;
                     
                    cout << "Inserting node....." << endl;
                     head=insert_at_end(head,val);
                    
                    break;
                case '3':
                    cout<<"Enter value to insert: ";
                    cin>>val;
                    cout<<"Enter position: ";
                    cin>>pos;
                    head=insert_after(head,val,pos);
                    
                    break;
                    case '4':
                    cout<<"Enter value to insert: ";
                    cin>>val;
                    cout<<"Enter position: ";
                    cin>>pos;
                    head=insert_before(head,val,pos);
                    
                    break;
                default:
                cout << "Invalid choice. Please enter 1, 2, 3 or 4.\n";
                continue;

            }
            traverse(head);

  
        cout << "\nDo you want to perform another insertion? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    cout << "Final length of the Circular Linked List: " << length_of_DCLL(head) << endl;

    return 0;
}

