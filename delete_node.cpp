#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:
    node (int data1,node* next1){
        data=data1;
        next=next1;
    }

    public:
    node(int data1){
        data=data1;
        next=nullptr;
    }
};
//DELETE AT THE BEGINNING
// DELETE AT THE BEGINNING
node* deleteNode(node* head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return nullptr;
    }

    node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

//DELETE AT ANY POSITION
node* deleteAtAnyPos(node* head,int val){
    node* temp=head;
    node* prev=NULL;
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return nullptr;
    }
     if (temp == nullptr) {
        cout << "Value not found in the list. Cannot delete." << endl;
        return head;
    }
    while(temp->data!=val){
        prev=temp;
        temp=temp->next;
    }
    //once temp is equal to the data
    prev->next=temp->next;
    delete(temp);
    return head;
}
//DELETE AT THE END
node* deleteAtEnd(node* head){
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return nullptr;
    }
    node* current=head;
    while(current->next->next!=nullptr){
        current=current->next;
    }
    free(current->next);
    current->next = nullptr;
    return head;
}
//CREATE LINKED LIST
node* createLL(vector<int>&arr){
    int n=arr.size();
    node* head=new node(arr[0]);
    node* move=head;
    for(int i=1;i<n;i++){
        node* temp=new node(arr[i]);
        move->next=temp;
        move=temp;
    }
    return head;

}//TRAVERSE THE NODE
void traverse(node* head){
    node* temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    
}
//DELETION ---->1. DELETION AT THE BEGINNING 2. DELETION AT THE END 3. DELETION AT ANY POSITION
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
        cout<<"1. Delete at the beginning\n";
        cout<<"2 Delete at the end\n";
        cout<<"3 Delete at any position except for beginning and the end position\n";
        cout<<" Enter your choice 1/2/3: \n";
        cin >> choice;

        
            int val,pos;
            switch(choice){
                case '1':
                     
                    cout << "Deleting node....." << endl;
                    head = deleteNode(head);
                    
                break;
                 case '2':
                     
                     
                    cout << "Deleting end node....." << endl;
                     head=deleteAtEnd(head);
                    
                    break;
                case '3':
                    cout<<"Enter value to delete: ";
                    cin>>val;
                    
                    head=deleteAtAnyPos(head,val);
                    
                    break;
                default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                continue;

            }
            
           
            traverse(head);

  
        cout << "\nDo you want to perform another deletion? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;

}
