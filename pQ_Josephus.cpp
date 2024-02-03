#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int player_id;
    struct Node *next;
};
int main(){
    int players,k,i,count;
    cout<<"Enter the number of players: ";
    cin>>players;
    cout<<"Enter the value of k (every kth player gets eliminated): ";
    cin>>k;
    //Create a circular linked list
    Node* head=new Node;
    head->player_id=1;
    Node* ptr=head;
    for(i=2;i<=players;i++){
        Node* newnode= new Node;
        ptr->next=newnode;
        newnode->player_id=i;
        newnode->next=head;
        ptr=newnode;
    }
for(count=players;count>1;count--){
    for(i=0;i<k-1;++i){
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;//Remove the eliminated player from the circular linked list
}
cout<<"The winner is player "<<ptr->player_id<<endl;
getchar();
return 0;
}
