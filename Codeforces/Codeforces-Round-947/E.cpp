
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

    int getDis(int u, int v) {
        return level[u] + level[v] - 2 * level[getLca(u, v)];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    vector<int> color(n + 1, 0);
    int numBlack = 0;
    fu(u, 1, n) {
        cin >> color[u];
        numBlack += color[u];
    }
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> level(n + 1, 0);
    LCA lca(n, adj);
    lca.build();
    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) continue;
            level[v] = level[u] + 1;
            dfs(v, u);
        }
    };
    dfs(1, -1);
    // fu(u, 1, n) {
    //     cout << u << " " << level[u] << "\n";
    // }

    map<int, set<int>> mp;
    fu(u, 1, n) {
        if (color[u] == 1) {
            mp[level[u]].insert(u);
        }
    }
    while (q-- > 0) {
        int u;
        cin >> u;
        if (color[u] == 1) {
            numBlack--;
            color[u] = 0;
            if (mp.find(level[u]) != mp.end()) {
                mp[level[u]].erase(u);
                if (mp[level[u]].empty()) {
                    mp.erase(level[u]);
                }
            }
        } else {
            numBlack++;
            color[u] = 1;
            mp[level[u]].insert(u);
        }
        if (numBlack == 0) {
            cout << "NO\n";
            continue;
        }
        if (numBlack == 1) {
            cout << "YES\n";
            continue;
        }
        auto low = mp.begin();
        auto high = mp.rbegin();
        if (low->ss.size() > 1) {
            cout << "NO\n";
            continue;
        }
        if (high->ss.size() > 2) {
            cout << "NO\n";
            continue;
        }
        if (high->ss.size() == 1) {
            int u = *low->ss.begin();
            int v = *high->ss.begin();
            if (lca.getDis(u, v) == numBlack - 1) {
                cout << "YES\n";
            } else {
                auto it = high;
                it++;
                bool ok = false;
                for (int z : it->ss) {
                    int uz = lca.getDis(u, z);
                    int uv = lca.getDis(u, v);
                    if (uz + uv == numBlack - 1) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        } else {
            int u = *low->ss.begin();
            int v = *high->ss.begin();
            int w = *next(high->ss.begin());
            int uv = lca.getDis(u, v);
            int uw = lca.getDis(u, w);
            if (uv + uw == numBlack - 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
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