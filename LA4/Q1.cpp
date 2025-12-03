#include <iostream>
using namespace std;

#define SIZE 5
int q[SIZE], f = -1, r = -1;

void enqueue() {
    int x; cin >> x;
    if (r == SIZE - 1) cout << "Overflow";
    else {
        if (f == -1) f = 0;
        q[++r] = x;
    }
}
void dequeue() {
    if (f == -1 || f > r) cout << "Underflow";
    else cout << q[f++];
}
void isEmpty() {
    if (f == -1 || f > r) cout << "Empty";
    else cout << "Not Empty";
}
void isFull() {
    if (r == SIZE - 1) cout << "Full";
    else cout << "Not Full";
}
void display() {
    for (int i = f; i <= r; i++) cout << q[i] << " ";
}
void peek() {
    if (f == -1 || f > r) cout << "No element";
    else cout << q[f];
}

int main() {
    int ch;
    while (1) {
        cin >> ch;
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) isEmpty();
        else if (ch == 4) isFull();
        else if (ch == 5) display();
        else if (ch == 6) peek();
        else break;
        cout << endl;
    }
}
