#include <iostream>
using namespace std;

#define len 10

int stack[len];
int top = -1;

void push(int value) {
    if (top >= len - 1) {
        cout <<"Stack overflow..\n";
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top < 0) {
        cout <<"Stack underflow\n";
        return;
    }
    cout <<"Popped element: " << stack[top] << "\n";
    top--;
}
bool isempty() {
    return top == -1;
}
bool isfull() {
    return top == len - 1;
}
int peek() {
    if (top >= 0)
        return stack[top];
    else {
        cout << "Stack is empty\n";
        return -1; 
    }
}

void display() {
    if (isempty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice, value;

    while (true) {
        cout <<"\n\nStack Menu \n";
        cout << "1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek (Top element)\n";
        cout << "4. Display\n";
        cout << "5. Check if stack is empty\n";
        cout<< "6. Check if stack is full\n";
        cout <<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if(value != -1) {
                    cout << "Top element is: " << value << "\n";
                }
                break;
            case 4:
                display();
                break;
            case 5:
                cout << (isempty()?"Stack is empty\n" :"Stack is not empty\n");
                break;
            case 6:
                cout << (isfull()?"Stack is full\n": "Stack is not full\n");
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
