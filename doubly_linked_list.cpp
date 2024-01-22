#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    public:
    node(int data1,node* next1,node* prev1){
data=data1;
next=next1;
prev=prev1;
    }
    node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
//CREATE DOUBLY LINKED LIST
node* createDLL(vector<int>& arr){
    int n=arr.size();
    node* head=new node(arr[0]);//arr[0],nullptr,nullptr;
    node* prev_node=head;
    for(int i=1;i<n;i++){
        node* current_node=new node(arr[i],nullptr,prev_node);
        prev_node->next=current_node;
        prev_node=current_node;
    }
    return head;
}
//INSERT AT THE BEGINNING
node* insertAtBeg(node* head,int n){
    node* newhead=new node(n,head,nullptr);
    head->prev=newhead;


    return newhead;
}
//INSERT AT THE END
node* insertAtEnd(node* head,int n){
    node* current=head;
    node* tail=new node(n);
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=tail;
    tail->prev=current;

    return head;
}
//INSERT BEFORE TAIL OR BEFORE END
node* insertBeforeTail(node* head,int n){
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node* previous_node=tail->prev;
    node* before_Tail=new node(n,tail,previous_node);
    previous_node->next=before_Tail;
    tail->prev=before_Tail;

    return head;
}
//INSERT AT KTH POSITION
node* insertAtKthPos(node* head,int k,int n){
    node* tail=head;
    int count=0;
    while(tail!=NULL){
        count=count+1;
        if(count==k)break;
        tail=tail->next;
    }
    node* previous_node=tail->prev;
    node* before_Tail=new node(n,tail,previous_node);
    previous_node->next=before_Tail;
    tail->prev=before_Tail;

    return head;
}node* insert_before(node* head, int element, int val) {
    node* current = new node(val);
    node* temp = head;
    int count = 1;

    // Find the node with data equal to element
    while (count < element-1) {
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

node* insert_after(node* head, int element, int val) {
    node* current = new node(val);
    node* temp = head;
    int count = 1;

    // Find the node with data equal to element
    while (count < element) {
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
//TRAVERSAL
void traverse(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main(){
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
  
   
 
   node* head=createDLL(arr);
   traverse(head);
   
  
    char choice;
     do {
        cout<<"\nChoose an option:"<<endl;
        cout<<"1. Insert at the beginning\n";
        cout<<"2 Insert at the end\n";
        cout<<"3 Insert at Kth position\n";
        cout<<"4 Insert before the given node\n";
        cout<<"5 Insert after the given node\n";
        cout<<"6 Insert before the end\n";
        cout<<" Enter your choice 1/2/3/4/5/6: \n";
        cin >> choice;

        
            int element,n,K,val;
            switch(choice){
                case '1':
                     cout << "Enter value to insert: ";
                     cin >> val;
                    cout << "Inserting node....." << endl;
                    head = insertAtBeg(head, val);
                    
                break;
                 case '2':
                     cout << "Enter value to insert: ";
                     cin >> val;
                     
                    cout << "Inserting node....." << endl;
                     head=insertAtEnd(head,val);
                    
                    break;
                case '3':
                    cout<<"K (pos): ";
                    cin>>K;
                    cout<<"Enter value: ";
                    cin>>val;
                    head=insertAtKthPos(head,K,val);
                    
                    break;
                case '4':
                cout<<"Enter the value before which the data has to be inserted: "<<endl;
                cin>>element;
                cout<<"Enter value";
                cin>>val;
                head=insert_before(head,element,val);
                break;
                
                case '5':
                cout<<"Enter the value after which the data has to be inserted: "<<endl;
                cin>>element;
                cout<<"Enter value";
                cin>>val;
                head=insert_after(head,element,val);
                break;
                case '6':

                default:
                cout << "Invalid choice. Please enter 1, 2,3,4,5 or 6.\n";
                continue;

            }
            traverse(head);

  
        cout << "\nDo you want to perform another insertion? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;

}
