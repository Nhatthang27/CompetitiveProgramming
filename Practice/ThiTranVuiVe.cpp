#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Dsu
{
    vector<int> root, sz;

    Dsu(int n)
    {
        root.assign(n + 1, -1);
        sz.assign(n + 1, 1);
        for (int u = 0; u < n; u++)
        {
            root[u] = u;
        }
    }

    int findRoot(int u)
    {
        return root[u] = (root[u] == u ? u : findRoot(root[u]));
    }

    bool join(int u, int v)
    {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v)
        {
            if (sz[u] < sz[v])
                swap(u, v);
            root[v] = u;
            sz[u] += sz[v];
            return true;
        }
        else
        {
            return false;
        }
    }
};

struct LCA
{
    int n;
    vector<vector<int>> p;
    vector<vector<int>> adj;
    vector<int> level;

    LCA(int n, vector<vector<int>> adj) : n(n), adj(adj)
    {
        p.assign(n + 1, vector<int>(20, -1));
        level.assign(n + 1, 0);
    }

    void preparePar(int u, int par)
    {
        p[u][0] = par;
        for (int v : adj[u])
        {
            if (v != par)
            {
                level[v] = level[u] + 1;
                preparePar(v, u);
            }
        }
    }

    void build()
    {
        preparePar(0, -1);
        for (int j = 1; j <= 19; j++)
            for (int i = 0; i < n; i++)
                if (p[i][j - 1] != -1)
                {
                    p[i][j] = p[p[i][j - 1]][j - 1];
                }
    }

    int getLca(int u, int v)
    {
        if (level[u] < level[v])
            swap(u, v);
        for (int i = 19; i >= 0; i--)
        {
            if (level[u] - (1 << i) >= level[v])
            {
                u = p[u][i];
            }
        }
        if (u == v)
            return u;
        for (int i = 19; i >= 0; i--)
        {
            if (p[u][i] != p[v][i])
            {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    }
};

struct custom_hash
{
    size_t operator()(const pair<int, int> &x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return hash<int>()(x.first) ^ (hash<int>()(x.second) + FIXED_RANDOM + (hash<int>()(x.first) << 6) + (hash<int>()(x.first) >> 2));
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 4>> edges(m);
    for (auto &[u, v, w, state] : edges)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        state = 0;
    }
    vector<int> route(k);
    for (auto &x : route)
    {
        cin >> x;
        x--;
    }

    Dsu dsu(n);
    sort(edges.begin(), edges.end(), [](array<int, 4> a, array<int, 4> b)
         { return a[2] < b[2]; });
    vector<vector<int>> adj(n);
    unordered_map<pair<int, int>, int, custom_hash> len;
    for (auto [u, v, w, state] : edges)
    {
        if (dsu.join(u, v))
        {
            state = 1;
            adj[u].push_back(v);
            len[{u, v}] = w;
        }
    }

    vector<int> dis(n, 0);
    function<void(int, int)> dfs = [&](int u, int par)
    {
        for (int v : adj[u])
        {
            if (v != par)
            {
                dis[v] = dis[u] + len[{u, v}];
                dfs(v, u);
            }
        }
    };
    dfs(0, -1);
    LCA lca(n, adj);
    lca.build();
    int res = 0;
    for (int i = 1; i < k; i++)
    {
        int u = route[i - 1];
        int v = route[i];
        int l = lca.getLca(u, v);
        res += dis[u] + dis[v] - 2 * dis[l];
    }
    cout << res << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}