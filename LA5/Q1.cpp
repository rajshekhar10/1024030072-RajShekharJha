#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insertBeg() {
    int x; cin >> x;
    Node* t = new Node{ x, head };
    head = t;
}

void insertEnd() {
    int x; cin >> x;
    Node* t = new Node{ x, NULL };
    if (!head) head = t;
    else {
        Node* p = head;
        while (p->next) p = p->next;
        p->next = t;
    }
}

void insertBefore() {
    int val, x; cin >> val >> x;
    if (!head) return;
    if (head->data == val) { insertBeg(); return; }
    Node* p = head;
    while (p->next && p->next->data != val) p = p->next;
    if (p->next) p->next = new Node{ x, p->next };
}

void insertAfter() {
    int val, x; cin >> val >> x;
    Node* p = head;
    while (p && p->data != val) p = p->next;
    if (p) p->next = new Node{ x, p->next };
}

void delBeg() {
    if (!head) return;
    Node* t = head; head = head->next; delete t;
}

void delEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = NULL; return; }
    Node* p = head;
    while (p->next->next) p = p->next;
    delete p->next; p->next = NULL;
}

void delSpecific() {
    int key; cin >> key;
    if (!head) return;
    if (head->data == key) { delBeg(); return; }
    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;
    if (p->next) {
        Node* t = p->next;
        p->next = t->next;
        delete t;
    }
}

void searchNode() {
    int x, pos = 1; cin >> x;
    Node* p = head;
    while (p) {
        if (p->data == x) { cout << pos; return; }
        pos++; p = p->next;
    }
    cout << -1;
}

void display() {
    Node* p = head;
    while (p) { cout << p->data << " "; p = p->next; }
}

int main() {
    int ch;
    while (1) {
        cin >> ch;
        if (ch == 1) insertBeg();
        else if (ch == 2) insertEnd();
        else if (ch == 3) insertBefore();
        else if (ch == 4) insertAfter();
        else if (ch == 5) delBeg();
        else if (ch == 6) delEnd();
        else if (ch == 7) delSpecific();
        else if (ch == 8) searchNode();
        else if (ch == 9) display();
        else break;
        cout << endl;
    }
}
