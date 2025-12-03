#include <iostream>
using namespace std;

#define SIZE 5
int stack[SIZE], top = -1;

void push() {
    int x;
    cin >> x;
    if (top == SIZE - 1) cout << "Overflow";
    else stack[++top] = x;
}

void pop() {
    if (top == -1) cout << "Underflow";
    else cout << stack[top--];
}

void isEmpty() {
    if (top == -1) cout << "Empty";
    else cout << "Not Empty";
}

void isFull() {
    if (top == SIZE - 1) cout << "Full";
    else cout << "Not Full";
}

void display() {
    for (int i = top; i >= 0; i--) cout << stack[i] << " ";
}

void peek() {
    if (top == -1) cout << "No element";
    else cout << stack[top];
}

int main() {
    int ch;
    while (1) {
        cin >> ch;
        if (ch == 1) push();
        else if (ch == 2) pop();
        else if (ch == 3) isEmpty();
        else if (ch == 4) isFull();
        else if (ch == 5) display();
        else if (ch == 6) peek();
        else break;
        cout << endl;
    }
}
