
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> p(n + 1, vector<int>(20, -1));
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> level(n + 1, -1);
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int u, int par) {
        for (int v : adj[u]) {
            if (v != par) {
                p[v][0] = u;
                level[v] = level[u] + 1;
                dfs(v, u);
            }
        }
    };

    level[1] = 0;
    dfs(1, -1);
    fu(i, 1, 19) {
        fu(u, 1, n) {
            if (p[u][i - 1] != -1) {
                p[u][i] = p[p[u][i - 1]][i - 1];
            }
        }
    }

    auto getLCA = [&](int u, int v) -> int {
        if (level[u] < level[v])
            swap(u, v);
        fd(i, 19, 0) {
            if (level[u] == level[v])
                break;
            int pu = p[u][i];
            if (pu != -1 && level[pu] >= level[v]) {
                u = pu;
            }
        }
        if (v == u)
            return u;
        fd(i, 19, 0) {
            if (p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    };

    while (q-- > 0) {
        int u, v;
        cin >> u >> v;
        int puv = getLCA(u, v);
        cout << level[u] + level[v] - 2 * level[puv] << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}