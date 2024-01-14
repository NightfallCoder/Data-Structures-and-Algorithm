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
node* createLL(vector<int>arr){
    int n=arr.size();
    node* head=new node (arr[0]);
    node* move=head;
    for(int i=1;i<n;i++){
        node* temp=new node(arr[i]);
        move->next=temp;
        move=temp;
    }
    return head;
}
void traverse(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
//insert at the beginning
node* insertNode(node* head,int n){
    
        
        node* temp= new node(n);
        temp->next=head;
        head=temp;
        return head;

}
//insert at the end
node* insertAtEnd(node* head,int n){
    node* move= head;
    node* temp=new node(n);
    while(move->next!=NULL){
        move=move->next;
    }
    move->next=temp;
    
   /*node* temp=head;
   node* newnode= new node(n);
   while(temp->next!=NULL){
    temp=temp->next;
   }
   temp->next=newnode;
*/
    return head;
    
}
node* insertAtAnyPos(node* head,int n,int pos){
    int i=1;
    node* current=head;
    node* specific=new node(n);
    
   while(i!=pos-1 && current!=nullptr){
    current=current->next;
    i++;
   }
   specific->next=current->next;
   current->next=specific;
   return head;
}
int main(){
    vector<int> arr;
    int n;
    cout<<"Enter size of the array: "<<" ";
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
   node* head=createLL(arr);
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
                    head = insertNode(head, val);
                    
                break;
                 case '2':
                     cout << "Enter value to insert: ";
                     cin >> val;
                     
                    cout << "Inserting node....." << endl;
                     head=insertAtEnd(head,val);
                    
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

    return 0;
}