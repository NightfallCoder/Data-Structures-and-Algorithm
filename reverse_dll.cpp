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
/*STACK METHOD(LIFO-LAST IN FIRST OUT)4->3->2->1
|     1    |
|     2    |
|          |
|    3     |
|          |
|   4      |
|_________ |
*/
/*node* reverse_dll(node* head){
    node*temp=head;
    stack <int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}*/

/*node* reverse_dll(node* head){
    node* temp=head;
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
   while (temp != tail && temp->prev != tail) {
    int tempData=temp->data;
    temp->data=tail->data;
    tail->data=tempData;
    temp=temp->next;
    tail=tail->prev;
   }
   return head;
}
*/
node* reverse_dll(node* head){
     if(head==NULL || head->next==NULL){
        return head;
    }
    node* current=head;
    node* temp=NULL;
   
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    return temp->prev;

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
  node* head=createDLL(vec);
  traverse(head);
  cout<<endl;
  head=reverse_dll(head);
  traverse(head);
}