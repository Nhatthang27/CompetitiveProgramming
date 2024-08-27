
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
    int n, m, c;
    cin >> n >> m >> c;
    struct Edge {
        int id, v;
        Edge(int id, int v) : id(id), v(v) {}
    };
    vector<vector<Edge>> edges(n + 1);
    fu(i, 1, m) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back({i, v});
        edges[v].push_back({i, u});
    }

    struct Bridge {
        int id, szChild, root;
        Bridge(int id, int szChild, int root) : id(id), szChild(szChild), root(root) {}
    };

    vector<Bridge> bridges;
    vector<int> sz(n + 1, 0), num(n + 1, 0), low(n + 1);
    function<void(int, int, int)> dfs = [&](int u, int p, int root) {
        sz[u] = 1;
        num[u] = low[u] = ++num[0];
        for (Edge e : edges[u]) {
            int v = e.v;
            if (v == p) continue;
            if (num[v]) {
                low[u] = min(low[u], num[v]);
            } else {
                dfs(v, u, root);
                low[u] = min(low[u], low[v]);
                sz[u] += sz[v];
                if (low[v] > num[u]) {
                    bridges.emplace_back(e.id, sz[v], root);
                }
            }
        }
    };
    auto getScore = [&](multiset<int> comps) {
        bitset<301> bs;
        bs[0] = 1;
        for (int x : comps) {
            bs |= bs << x;
        }
        int ret = 1e18;
        for (int i = 0; i <= n; ++i) {
            if (!bs[i]) continue;
            ret = min(ret, 1LL * i * i + 1LL * (n - i) * (n - i));
        }
        return ret;
    };

    multiset<int> compSizes;
    int numComp = 0;

    fu(u, 1, n) {
        if (num[u]) continue;
        dfs(u, -1, u);
        numComp++;
        compSizes.insert(sz[u]);
    }
    // for (auto x : compSizes) cerr << x << " ";
    // cerr << "\n";

    int base = (numComp - 1) * c;
    int res = (numComp == 1 ? LONG_LONG_MAX : getScore(compSizes) + base);

    // cerr << res << " " << base << "\n";
    for (auto [id, szChild, root] : bridges) {
        compSizes.erase(compSizes.find(sz[root]));
        compSizes.insert(szChild);
        compSizes.insert(n - szChild);
        res = min(res, base + getScore(compSizes));
        compSizes.erase(compSizes.find(szChild));
        compSizes.erase(compSizes.find(n - szChild));
        compSizes.insert(sz[root]);
    }
    cout << (res == LONG_LONG_MAX ? -1 : res) << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}