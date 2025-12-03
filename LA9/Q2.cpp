#include <bits/stdc++.h>
using namespace std;

vector<int> g[100]; int vis[100];

void dfs(int x) {
    vis[x] = 1;
    cout << x << " ";
    for (int i : g[x])
        if (!vis[i]) dfs(i);
}

int main() {
    int n, e, u, v, s;
    cin >> n >> e;
    while (e--) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> s;
    dfs(s);
}
