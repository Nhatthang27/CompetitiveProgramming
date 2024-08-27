#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int const N = 2e5 + 5;
int n, t, d[N];
vector<int> g[N];

bool dfs(int x, int p) {
    for (int u : g[x])
        if (u != p && !dfs(u, x)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < t; ++i) {
        int u;
        cin >> u;
        cout << (dfs(u, 0) ? "Ron\n" : "Hermione\n");
    }
}