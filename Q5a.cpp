#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q1.push(x);
    cout << x << " pushed" << endl;
}

void pop() {
    if (q1.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }
    cout << q1.front() << " popped" << endl;
    q1.pop();
    swap(q1, q2);
}

void top() {
    if (q1.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }
    cout << "Top element: " << q1.front() << endl;
    q2.push(q1.front());
    q1.pop();
    swap(q1, q2);
}

int main() {
    int choice, val;

    while (true) {
        cout << "\nMenu (Stack using Two Queues):\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}
