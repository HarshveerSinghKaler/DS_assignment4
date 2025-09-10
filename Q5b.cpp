#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x) {
    q.push(x);
    int sz = q.size();
    for (int i = 0; i < sz - 1; i++) {
        q.push(q.front());
        q.pop();
    }
    cout << x << " pushed" << endl;
}

void pop() {
    if (q.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << q.front() << " popped" << endl;
    q.pop();
}

void top() {
    if (q.empty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << "Top element: " << q.front() << endl;
}

int main() {
    int choice, val;

    while (true) {
        cout << "\nMenu (Stack using One Queue):\n";
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
