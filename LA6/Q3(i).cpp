#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node* prev; };
Node* head = NULL;

int main() {
    int n, x, cnt = 0;
    cin >> n;
    while (n--) { cin >> x; head = new Node{ x, head, NULL }; if (head->next) head->next->prev = head; }
    Node* p = head;
    while (p) { cnt++; p = p->next; }
    cout << cnt;
}
