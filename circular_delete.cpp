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
//DELETE AT THE BEGINNING
Node* delete_at_beg(Node* head){
    Node* tail=head;
    Node* temp=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    head=head->next;
    tail->next=head;
    free(temp);
    return head;
}
//DELETE AT THE END
Node* delete_at_end(Node* head){
    Node* temp,*current;
    temp=head;
    while(temp->next!=head){
        current=temp;
        temp=temp->next;
    }
    current->next=head;
    free(temp);
    return head;
}
int main(){
    vector<int>vec;
    int size,num;
    cout<<"Enter size of the element: "<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>num;
        vec.push_back(num);
    }
    Node* head=createCLL(vec);
    traverse(head);
    cout<<endl;

    head=delete_at_beg(head);
    traverse(head);
    
    cout<<endl;

    head=delete_at_end(head);
    traverse(head);
}