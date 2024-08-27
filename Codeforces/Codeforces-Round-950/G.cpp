
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

    int getDist(int u, int v) {
        return level[u] + level[v] - 2 * level[getLca(u, v)];
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<pii>> adj(n + 1);
    vector<vector<int>> a(n + 1);
    fu(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(v);
        a[v].push_back(u);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    LCA lca(n, a);
    lca.build();
    vector<int> up(n + 1, 0), down(n + 1, 0);
    down[0] = -1;
    function<void(int, int)> dfs1 = [&](int u, int par) {
        for (auto [v, w] : adj[u]) {
            if (v != par) {
                dfs1(v, u);
                down[u] = max(down[u], down[v] | w);
            }
        }
    };
    dfs1(1, -1);

    function<void(int, int)> dfs2 = [&](int u, int par) {
        pii greatest = {0, 0};
        for (auto [v, w] : adj[u]) {
            if (v != par) {
                if ((down[v] | w) > down[greatest.ff]) {
                    greatest.ss = greatest.ff;
                    greatest.ff = v;
                } else if ((down[v] | w) > down[greatest.ss]) {
                    greatest.ss = v;
                }
            }
        }
        for (auto [v, w] : adj[u]) {
            if (v != par) {
                up[v] = max(up[u] | w, (v == greatest.ff ? down[greatest.ss]
                                                         : down[greatest.ff]) |
                                           w);
                dfs2(v, u);
            }
        }
    };
    dfs2(1, -1);
    // cout << "here\n";
    int sum_or = 0;
    while (q-- > 0) {
        char type;
        cin >> type;
        if (type == '^') {
            int x;
            cin >> x;
            sum_or |= x;
        } else {
            int u, x;
            cin >> u >> x;
            cout << (max(up[u], down[u]) | sum_or | x) << " ";
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}