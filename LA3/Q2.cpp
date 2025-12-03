#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s, r;
    cin >> s;
    stack<char> st;
    for (char c : s) st.push(c);
    while (!st.empty()) {
        r += st.top();
        st.pop();
    }
    cout << r;
}
