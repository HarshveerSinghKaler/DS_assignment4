#include <iostream>
using namespace std;

#define SIZE 5

bool isEmpty(int front);
bool isFull(int front, int rear);
void enqueue(int arr[], int &front, int &rear, int val);
void dequeue(int arr[], int &front, int &rear);
void peek(int arr[], int front);
void display(int arr[], int front, int rear);

int main() {
    int arr[SIZE];
    int front = -1, rear = -1;
    int choice, val;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. IsEmpty\n";
        cout << "6. IsFull\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(arr, front, rear, val);
                break;
            case 2:
                dequeue(arr, front, rear);
                break;
            case 3:
                peek(arr, front);
                break;
            case 4:
                display(arr, front, rear);
                break;
            case 5:
                cout << (isEmpty(front) ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 6:
                cout << (isFull(front, rear) ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}

bool isEmpty(int front) {
    return (front == -1);
}

bool isFull(int front, int rear) {
    return ((rear + 1) % SIZE == front);
}

void enqueue(int arr[], int &front, int &rear, int val) {
    if (isFull(front, rear)) {
        cout << "Queue is Full!" << endl;
        return;
    }
    if (isEmpty(front)) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    arr[rear] = val;
    cout << val << " enqueued" << endl;
}

void dequeue(int arr[], int &front, int &rear) {
    if (isEmpty(front)) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << arr[front] << " dequeued" << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void peek(int arr[], int front) {
    if (isEmpty(front)) {
        cout << "Queue is Empty!" << endl;
    } else {
        cout << "Front element: " << arr[front] << endl;
    }
}

void display(int arr[], int front, int rear) {
    if (isEmpty(front)) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}
