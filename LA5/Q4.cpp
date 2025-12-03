#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

int main() {
    int n, x;
    cin >> n;
    while (n--) { cin >> x; head = new Node{ x, head }; }
    Node* prev = NULL;
    Node* cur = head;
    Node* nxt;
    while (cur) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
    Node* p = head;
    while (p) { cout << p->data << " "; p = p->next; }
}
