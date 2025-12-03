#include <iostream>
#include <stack>
using namespace std;

int main() {
    string p;
    cin >> p;
    stack<int> st;
    for (char c : p) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (c=='+') st.push(a+b);
            else if (c=='-') st.push(a-b);
            else if (c=='*') st.push(a*b);
            else if (c=='/') st.push(a/b);
        }
    }
    cout << st.top();
}
