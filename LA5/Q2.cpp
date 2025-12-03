#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

int main() {
    int n, x, key, c = 0;
    cin >> n;
    while (n--) { cin >> x; head = new Node{ x, head }; }
    cin >> key;
    Node* p = head;
    while (p) { if (p->data == key) c++; p = p->next; }
    while (head && head->data == key) { p = head; head = head->next; delete p; }
    p = head;
    while (p && p->next) {
        if (p->next->data == key) {
            Node* t = p->next;
            p->next = t->next;
            delete t;
        } else p = p->next;
    }
    cout << "Count: " << c << " , Updated Linked List: ";
    p = head;
    while (p) { cout << p->data << " "; p = p->next; }
}
