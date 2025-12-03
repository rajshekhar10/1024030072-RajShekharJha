#include <iostream>
using namespace std;

#define SIZE 5
int cq[SIZE], f = -1, r = -1;

void enqueue() {
    int x; cin >> x;
    if ((r + 1) % SIZE == f) cout << "Overflow";
    else {
        if (f == -1) f = 0;
        r = (r + 1) % SIZE;
        cq[r] = x;
    }
}
void dequeue() {
    if (f == -1) cout << "Underflow";
    else {
        cout << cq[f];
        if (f == r) f = r = -1;
        else f = (f + 1) % SIZE;
    }
}
void isEmpty() {
    if (f == -1) cout << "Empty";
    else cout << "Not Empty";
}
void isFull() {
    if ((r + 1) % SIZE == f) cout << "Full";
    else cout << "Not Full";
}
void display() {
    if (f == -1) return;
    int i = f;
    while (true) {
        cout << cq[i] << " ";
        if (i == r) break;
        i = (i + 1) % SIZE;
    }
}
void peek() {
    if (f == -1) cout << "No element";
    else cout << cq[f];
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
