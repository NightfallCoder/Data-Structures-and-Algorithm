#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* createCLL(vector<int>arr){
    int n=arr.size();
    if (n == 0) {
        return nullptr; // Return nullptr for an empty list
    }
    Node* head=new Node (arr[0]);
    Node* move=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        move->next=temp;
        move=temp;
    }
    move->next=head;
    if (n == 1) {
        head->next = head;
    }

    return head;
}
void traverse(Node* head) {
   
    Node* temp = head;
    
    do {
        cout<<temp->data << "->";
        temp = temp->next;
    } while (temp != head);
}
//INSERT AT THE BEGINNING
Node* insert_at_beg(Node* head,int val){
    Node* tail=head;
    Node* newnode= new Node(val);
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=newnode;
    newnode->next=head;

    return newnode;
}
//INSERT AT THE END
Node* insert_at_end(Node* head,int val){
    Node* tail= head;
    Node* newnode=new Node(val);
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=newnode;
    newnode->next= head;
    return head;
}
//INSERT AT ANY POS
Node* insertAtAnyPos(Node* head,int n,int pos){
    int i=1;
    Node* current=head;
    Node* specific=new Node(n);
    
   while(i!=pos-1 && current!=nullptr){
    current=current->next;
    i++;
   }
   specific->next=current->next;
   current->next=specific;
   return head;
}
//LENGTH
int length_of_LL(Node* head){
    Node* temp=head;
    int count=1;
    while(temp->next!=head){
        temp=temp->next;
        count++;
    }
    return count;
}
int main(){
    vector<int>vec;
    int size;
    cout<<"Size of the element: "<<endl;
    cin>>size;
    int num;
    for(int i=0;i<size;i++){
        cin>>num;
        vec.push_back(num);
    }
    Node* head= createCLL(vec);
    traverse(head);
    char choice;
     do {
        cout<<"\nChoose an option:"<<endl;
        cout<<"1. Insert at the beginning\n";
        cout<<"2 Insert at the end\n";
        cout<<"3 Insert at any position except for beginning and the end position\n";
        cout<<" Enter your choice 1/2/3: \n";
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
                    head=insertAtAnyPos(head,val,pos);
                    
                    break;
                default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                continue;

            }
            traverse(head);

  
        cout << "\nDo you want to perform another insertion? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    cout << "Final length of the Circular Linked List: " << length_of_LL(head) << endl;

    return 0;
}