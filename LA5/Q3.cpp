#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

int main() {
    int n, x;
    cin >> n;
    while (n--) { cin >> x; head = new Node{ x, head }; }
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}
