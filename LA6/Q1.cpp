#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insert(int x, int pos) {
    Node* t = new Node{ x, NULL };
    if (!head) { head = t; t->next = head; return; }
    if (pos == 0) {
        Node* p = head;
        while (p->next != head) p = p->next;
        t->next = head;
        p->next = t;
        head = t;
        return;
    }
    Node* p = head;
    while (--pos && p->next != head) p = p->next;
    t->next = p->next;
    p->next = t;
}

void insertBefore(int val, int x) {
    if (!head) return;
    if (head->data == val) { insert(x, 0); return; }
    Node* p = head;
    while (p->next != head && p->next->data != val) p = p->next;
    if (p->next != head) p->next = new Node{ x, p->next };
}

void insertAfter(int val, int x) {
    Node* p = head;
    while (p->next != head && p->data != val) p = p->next;
    if (p->data == val) p->next = new Node{ x, p->next };
}

void del(int key) {
    if (!head) return;
    Node* p = head;
    if (head->data == key) {
        if (head->next == head) { delete head; head = NULL; return; }
        while (p->next != head) p = p->next;
        Node* t = head;
        head = head->next;
        p->next = head;
        delete t;
        return;
    }
    while (p->next != head && p->next->data != key) p = p->next;
    if (p->next != head) {
        Node* t = p->next;
        p->next = t->next;
        delete t;
    }
}

void search(int x) {
    if (!head) { cout << -1; return; }
    Node* p = head; int pos = 1;
    do {
        if (p->data == x) { cout << pos; return; }
        pos++; p = p->next;
    } while (p != head);
    cout << -1;
}

void display() {
    if (!head) return;
    Node* p = head;
    do { cout << p->data << " "; p = p->next; } while (p != head);
}

int main() {
    int ch, x, pos, val;
    while (1) {
        cin >> ch;
        if (ch == 1) cin >> x >> pos, insert(x, pos);
        else if (ch == 2) cin >> val >> x, insertBefore(val, x);
        else if (ch == 3) cin >> val >> x, insertAfter(val, x);
        else if (ch == 4) cin >> x, del(x);
        else if (ch == 5) cin >> x, search(x);
        else if (ch == 6) display();
        else break;
        cout << endl;
    }
}
