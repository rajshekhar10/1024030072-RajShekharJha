#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

int main() {
    int n, x, cnt = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        Node* t = new Node{ x, NULL };
        if (!head) { head = t; t->next = head; }
        else { Node* p = head; while (p->next != head) p = p->next; p->next = t; t->next = head; }
    }
    Node* p = head;
    do { cnt++; p = p->next; } while (p != head);
    cout << cnt;
}
