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

//TRAVERSAL
void traverse(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
//DELETE AT THE BEGINNING
node* deleteNodeAtBeg(node* head){
    if(head==NULL){
        return NULL;
    }
    node* temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);

    return head;
} 
//DELETE AT THE END
node* deleteNodeATEnd(node* head){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->prev->next=nullptr;
    return head;
}
//DELETE NODE AFTER A GIVEN POS
node* deleteAfterPos(node* head,int pos){
    node* current=head;
    node* temp;
    int count=1;
    while(count<pos && current!=NULL){
        
            current=current->next;
            count++;
    } 
    temp= current->next;
        current->next=current->next->next;
        current->next->prev=current;
        free(temp);
        return head;
    
}
//DELETE NODE BEFORE A GIVEN POS
node* deleteBeforePos(node* head,int pos){
    node* current=head;
    node* temp;
    int count=1;
     while(count<pos-1 && current!=NULL){
        
            current=current->next;
            count++;
    } 
    temp=current;
    current->next->prev=current->prev;
    current->prev->next=current->next;
    free(temp);
    return head;
}
int main(){
  vector<int>vec;
  int n;
  cout<<"Enter size: ";
  cin>>n;  
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    vec.push_back(num);
  }
  cout<<"<-------Create Doubly Linked List------>"<<endl;
  node* head=createDLL(vec);
  traverse(head);
  cout<<endl;
  cout<<"-------Delete In the Beginning-------->"<<endl;
  head= deleteNodeAtBeg(head);
  traverse(head);
  cout<<endl;
    cout<<"-------Delete In the End-------->"<<endl;
  head=deleteNodeATEnd(head);
  traverse(head);
  cout<<endl;
    cout<<"-------Delete After given position-------->"<<endl;
  int pos;
  cout<<"Enter position to delete after the given position: ";
  cin>>pos;
  head=deleteAfterPos(head,pos);
  traverse(head);
  cout<<endl;
    cout<<"-------Delete Before the Given postion -------->"<<endl;
  cout<<"Enter position to delete before the given position: ";
  cin>>pos;
  head=deleteBeforePos(head,pos);
  traverse(head);
}