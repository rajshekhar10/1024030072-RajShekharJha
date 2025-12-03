#include <iostream>
using namespace std;

struct Node { char data; Node* next; Node* prev; };
Node* head = NULL;

int main() {
    int n; char x;
    cin >> n;
    while (n--) {
        cin >> x;
        head = new Node{ x, head, NULL };
        if (head->next) head->next->prev = head;
    }
    Node* l = head;
    Node* r = head;
    while (r->next) r = r->next;
    while (l && r && l != r && r->next != l) {
        if (l->data != r->data) { cout << "Not Palindrome"; return 0; }
        l = l->next;
        r = r->prev;
    }
    cout << "Palindrome";
}
