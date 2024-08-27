
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int f = 0;
    vector<int> mt(4 * m, -1);
    vector<bool> vis(n + 1, 0);

    function<bool(int)> dfs = [&](int u) -> bool {
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
    };

    for (int u = 1; u <= n; u++) {
        vis.assign(n + 1, 0);
        f += dfs(u);
    }
    cout << f << "\n";
    fu(u, 1, n) {
        if (mt[u] != -1) {
            cout << mt[u] << " " << u << "\n";
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}