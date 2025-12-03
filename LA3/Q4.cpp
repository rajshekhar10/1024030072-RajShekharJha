#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if (c=='^') return 3;
    if (c=='*' || c=='/') return 2;
    if (c=='+' || c=='-') return 1;
    return 0;
}

int main() {
    string in, post;
    cin >> in;
    stack<char> st;
    for (char c : in) {
        if (isalnum(c)) post += c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while (!st.empty() && st.top()!='(') { post+=st.top(); st.pop(); }
            st.pop();
        } else {
            while (!st.empty() && prec(c) <= prec(st.top())) { post+=st.top(); st.pop(); }
            st.push(c);
        }
    }
    while (!st.empty()) { post += st.top(); st.pop(); }
    cout << post;
}
