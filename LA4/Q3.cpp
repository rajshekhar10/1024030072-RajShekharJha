#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    queue<int> q1, q2, q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < n / 2; i++) { q1.push(q.front()); q.pop(); }
    while (!q.empty()) { q2.push(q.front()); q.pop(); }
    while (!q1.empty() && !q2.empty()) {
        cout << q1.front() << " " << q2.front() << " ";
        q1.pop(); q2.pop();
    }
}
