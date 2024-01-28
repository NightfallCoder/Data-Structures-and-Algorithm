#include <bits/stdc++.h>
using namespace std;
#define n 5

class Queue {
    int *array;
    int front;
    int back;

public:
    Queue() {
        array = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x) {
        if (back == n - 1) {
            cout << "Queue overflow!!";
            return;
        }
        back++;
        array[back] = x;

        if (front == -1) {
            front++;
        }
    }

    void pop() {
        if (front == -1 || front > back) {
            cout << "No elements in queue";
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1 || front > back) {
            cout << "No elements in queue";
            return -1;
        }
        return array[front];
    }

    bool empty() {
        return (front == -1 || front > back);
    }

    void display() {
        if (front == -1 || front > back)
            cout << "Queue is empty";
        else {
            for (int i = front; i <= back; i++)
                cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q; // Create an instance of the Queue class
    int ch, num;

    do {
        cout << "1) Insert element to queue" << endl;
        cout << "2) Delete element from queue" << endl;
        cout << "3) Display all the elements of queue" << endl;
        cout << "4) Peek" << endl;
        cout << "5) Empty?" << endl;
        cout << "6) Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> num;
                q.push(num);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Peek: " << q.peek() << endl;
                break;
            case 5:
                cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 6:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 6);

    return 0;
}
