
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct custom_hash
{
    size_t operator()(pair<int, int> x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t hash1 = x.first + FIXED_RANDOM;
        uint64_t hash2 = x.second + FIXED_RANDOM;
        hash1 ^= (hash1 >> 16);
        hash2 ^= (hash2 >> 16);
        return hash1 ^ (hash2 << 1);
    }
};

struct Dsu
{
    vector<int> root, sz;

    Dsu(int n)
    {
        root.assign(n, -1);
        sz.assign(n, 1);
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

    bool sameSet(int u, int v)
    {
        return findRoot(u) == findRoot(v);
    }
};

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    Dsu f(n);
    Dsu g(n);
    vector<pair<int, int>> edges_f(m1);
    vector<pair<int, int>> edges_g(m2);
    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges_f[i] = {a, b};
        f.join(a, b);
    }
    for (int i = 0; i < m2; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges_g[i] = {a, b};
        g.join(a, b);
    }

    int res = 0;
    Dsu new_f(n);
    for (auto [i, j] : edges_f)
    {
        if (!g.sameSet(i, j))
        {
            res++;
        }
        else
        {
            new_f.join(i, j);
        }
    }
    for (auto [i, j] : edges_g)
    {
        // cerr << i << " " << j << endl;
        if (!new_f.sameSet(i, j))
        {
            res++;
            new_f.join(i, j);
        }
    }
    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}