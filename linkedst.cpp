#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void push(Node** top, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    cout << "Pushed " << value << " onto the stack.\n";
}
void pop(Node** top) {
    if (*top == nullptr) {
        cout << "Stack is empty. Cannot pop.\n";
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
    cout << "Popped " << temp->data << " from the stack.\n";
    delete temp;
}
void display(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack elements: ";
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << "\n";
}
int main() {
    Node* top = nullptr;
    int choice, value;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}