#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct LCA {
    int n;
    vector<vector<int>> p;
    vector<vector<int>> adj;
    vector<int> level;

    LCA(int n, vector<vector<int>> adj) : n(n), adj(adj) {
        p.assign(n + 1, vector<int>(20, -1));
        level.assign(n + 1, 0);
        build();
    }

    void preparePar(int u, int par) {
        p[u][0] = par;
        for (int v : adj[u]) {
            if (v != par) {
                level[v] = level[u] + 1;
                preparePar(v, u);
            }
        }
    }

    void build() {
        preparePar(1, -1);
        fu(j, 1, 19) {
            fu(i, 1, n) {
                if (p[i][j - 1] != -1) {
                    p[i][j] = p[p[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getLca(int u, int v) {
        if (level[u] < level[v])
            swap(u, v);
        fd(i, 19, 0) {
            if (level[u] - (1 << i) >= level[v]) {
                u = p[u][i];
            }
        }
        if (u == v)
            return u;
        fd(i, 19, 0) {
            if (p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1, vector<int>());
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LCA lca(n, adj);
    vector<int> res(n + 1, 0);
    while (q-- > 0) {
        int u, v;
        cin >> u >> v;
        int puv = lca.getLca(u, v);
        res[puv]--;
        res[u]++;
        res[v]++;
        if (lca.level[puv] > 0) {
            res[lca.p[puv][0]]--;
        }
    }
    function<void(int, int)> dfs = [&](int u, int par) {
        for (int v : adj[u]) {
            if (v != par) {
                dfs(v, u);
                res[u] += res[v];
            }
        }
    };
    dfs(1, -1);
    fu(i, 1, n) cout << res[i] << " ";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}