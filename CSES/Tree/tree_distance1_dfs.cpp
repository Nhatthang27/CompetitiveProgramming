#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e5 + 7;

int n;
vector<vector<int>> adj;

void enter() {
    cin >> n;
    adj.resize(n + 1);
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void find_leaf(int u, int par, int depth, int &maxDepth, int &leaf) {
    if (depth >= maxDepth) {
        maxDepth = depth;
        leaf = u;
    }
    for (int v : adj[u]) {
        if (v != par) {
            find_leaf(v, u, depth + 1, maxDepth, leaf);
        }
    }
}

void solve() {
    int leaf1, leaf2, dmax = 0;

    find_leaf(1, -1, 0, dmax, leaf1);
    find_leaf(leaf1, -1, 0, dmax, leaf2);

    vector<int> longest(n + 1, 0);

    function<void(int, int, int)> dfs = [&](int u, int par, int depth) {
        longest[u] = max(longest[u], depth);
        for (int v : adj[u]) {
            if (v != par) {
                dfs(v, u, depth + 1);
            }
        }
    };

    dfs(leaf1, -1, 0);
    dfs(leaf2, -1, 0);
    fu(u, 1, n) { cout << longest[u] << " "; }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    solve();
}