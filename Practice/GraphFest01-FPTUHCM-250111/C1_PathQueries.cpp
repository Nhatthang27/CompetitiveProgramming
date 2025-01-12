
#include <bits/stdc++.h>
#define int long long
using namespace std;

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

    int join(int u, int v)
    {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v)
        {
            if (sz[u] < sz[v])
                swap(u, v);
            root[v] = u;
            int ways = sz[u] * sz[v];
            sz[u] += sz[v];
            return ways;
        }
        else
        {
            return 0;
        }
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> edges(n - 1);
    for (auto &[u, v, w] : edges)
    {
        cin >> u >> v >> w;
        u--;
        v--;
    }
    sort(edges.begin(), edges.end(), [&](array<int, 3> x, array<int, 3> y)
         { return x[2] < y[2]; });
    vector<pair<int, int>> redis;
    Dsu dsu(n);
    for (auto [u, v, w] : edges)
    {
        int ways = dsu.join(u, v);
        if (redis.empty())
        {
            redis.push_back({w, ways});
        }
        else
        {
            if (redis.back().first == w)
            {
                redis.back().second += ways;
            }
            else
            {
                redis.push_back({w, redis.back().second + ways});
            }
        }
    }
    // for (auto [w, ways] : redis)
    // {
    //     cerr << w << " " << ways << "\n";
    // }
    while (q-- > 0)
    {
        int k;
        cin >> k;
        int ans = 0;
        int l = 0;
        int r = (int)redis.size() - 1;
        int res = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // cerr << l << " " << r << " " << mid << " " << redis[mid].first << " " << redis[mid].second << "\n";
            if (redis[mid].first <= k)
            {
                l = mid + 1;
                res = redis[mid].second;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << res << " ";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}