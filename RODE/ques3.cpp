
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Kuhn {
    int n, m;
    vector<vector<int>> adj;
    vector<int> mt;
    vector<bool> vis;

    Kuhn(int _n = 0, int _m = 0) {
        n = _n, m = _m;
        adj.assign(n + 1, vector<int>());
        mt.assign(m + 1, -1);
        vis.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool dfs(int u) {
        if (vis[u])
            return 0;
        vis[u] = 1;
        for (int v : adj[u]) {
            if (mt[v] < 0 || dfs(mt[v])) {
                mt[v] = u;
                return 1;
            }
        }
        return 0;
    }

    int getMaxMatching() {
        int res = 0;
        fu(u, 1, n) {
            vis.assign(n + 1, 0);
            res += dfs(u);
        }
        return res;
    }
};
void solve() {
    int n, m;
    cin >> n >> m >> k;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}