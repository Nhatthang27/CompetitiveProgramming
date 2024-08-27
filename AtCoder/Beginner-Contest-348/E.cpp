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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> numChild(n + 1, 0);
    vector<int> down(n + 1, 0);
    vector<int> up(n + 1, 0);

    int total = 0;
    fu(i, 1, n) cin >> numChild[i], total += numChild[i];

    function<void(int, int)> dfsDown = [&](int u, int p) {
        down[u] = 0;
        for (int v : adj[u]) {
            if (v == p)
                continue;
            dfsDown(v, u);
            down[u] += down[v] + numChild[v];
            numChild[u] += numChild[v];
        }
    };

    dfsDown(1, -1);

    function<void(int, int)> dfsUp = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p)
                continue;
            up[v] =
                (down[u] - down[v] - numChild[v]) + numChild[u] - numChild[v];
            up[v] += up[u] + total - numChild[u];
            dfsUp(v, u);
        }
    };
    dfsUp(1, -1);
    int res = LONG_LONG_MAX;
    fu(i, 1, n) res = min(res, up[i] + down[i]);
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}