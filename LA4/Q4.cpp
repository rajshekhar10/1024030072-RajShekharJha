#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    queue<char> q;
    int f[26] = {0};
    for (char c : s) {
        f[c - 'a']++;
        q.push(c);
        while (!q.empty() && f[q.front() - 'a'] > 1) q.pop();
        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }
}
