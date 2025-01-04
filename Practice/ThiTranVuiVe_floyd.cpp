
#include <bits/stdc++.h>
#define int long long
using namespace std;
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
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    unordered_map<pair<int, int>, int, custom_hash> mp;
    vector<int> path(k);
    for (auto &x : path)
    {
        cin >> x;
        x--;
    }
    int res = 0;
    for (int i = 1; i < k; i++)
    {
        int u = path[i - 1], v = path[i];
        if (u > v)
            swap(u, v);
        if (mp.count({u, v}))
        {
            res += mp[{u, v}];
            continue;
        }
        mp[{u, u}] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e18);
        dist[u] = 0;
        pq.push({0, u});
        while (!pq.empty())
        {
            auto [d, x] = pq.top();
            pq.pop();
            mp[{u, x}] = d;
            if (x == v)
            {
                res += d;
                break;
            }
            if (d != dist[x])
                continue;
            for (auto [y, w] : adj[x])
            {
                if (mp.count({x, y}))
                    w = mp[{x, y}];
                if (dist[y] > dist[x] + w)
                {
                    dist[y] = dist[x] + w;
                    pq.push({dist[y], y});
                }
            }
        }
    }
    cout << res;
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