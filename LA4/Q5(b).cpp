#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int ch, x;
    while (1) {
        cin >> ch;
        if (ch == 1) {
            cin >> x;
            int n = q.size();
            q.push(x);
            while (n--) { q.push(q.front()); q.pop(); }
        }
        else if (ch == 2) {
            if (q.empty()) cout << "Empty";
            else { cout << q.front(); q.pop(); }
        }
        else break;
        cout << endl;
    }
}
