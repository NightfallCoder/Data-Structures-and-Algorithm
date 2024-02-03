#include <iostream>
using namespace std;

class Node {
public:
    int value;
    int priority;
    Node* next;

    Node(int value1, int priority1, Node* next1) {
        value = value1;
        priority = priority1;
        next = next1;
    }

    Node(int value1, int priority1) {
        value = value1;
        priority = priority1;
        next = nullptr;
    }
};

Node* insert_pq(Node* head, int val, int pri) {
    
    Node* ptr = new Node(val, pri);
 
    Node* p;
    if (head == NULL || pri < head->priority) {
        ptr->next = head;
        head = ptr;
    } else {
        p = head;
        
        while (p->next != NULL && p->next->priority <= pri) {
            p = p->next;
        }
       
        ptr->next = p->next;
        p->next = ptr;
        
    }
    return head;
}

Node* delete_PQ(Node* head) {
    Node* ptr;
    if (head == NULL) {
        cout << "UNDERFLOW!!";
    } else {
        ptr = head;
        cout << "Deleted Item is: " << ptr->value << " (" << ptr->priority << ")";
        head = head->next;
        delete ptr;  // Use delete instead of free
    }
    return head;
}

void display(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Priority Queue is: ";
        while (temp != NULL) {
            cout << temp->value << "(" << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int value, pri, option;
    Node* head = NULL;  // Declare head outside the loop

    do {
        cout << "MAIN MENU" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. DISPLAY" << endl;
        cout << "4. EXIT" << endl;
        cout << "Choose your option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Input Value: " << endl;
                cin >> value;
                cout << "Input priority: " << endl;
                cin >> pri;
                head = insert_pq(head, value, pri);
                break;

            case 2:
                head = delete_PQ(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                cout << "EXIT" << endl;
                break;
        }

    } while (option != 4);

    return 0;
}
