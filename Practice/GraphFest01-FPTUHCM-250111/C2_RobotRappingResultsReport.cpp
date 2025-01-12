
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> inDeg(n, 0);
    vector<pair<int, int>> edges(m);
    for (auto &[u, v] : edges)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDeg[i] == 0)
        {
            if (!q.empty())
            {
                cout << -1;
                return;
            }
            q.push(i);
        }
    }
    vector<int> level(n, 0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            inDeg[v]--;
            if (inDeg[v] == 0)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cerr << i + 1 << " " << level[i] << "\n";
    // }
    set<pair<int, int>> s;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++)
    {
        int u = level[edges[i].first];
        int v = level[edges[i].second];
        if (u + 1 != v) continue;
        if (mp[{u, v}] == 1)
        {
            s.insert({u, v});
        }
        mp[{u, v}]++;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        int u = level[edges[i].first];
        int v = level[edges[i].second];
        if (u + 1 != v) continue;
        if (s.empty())
        {
            cout << i + 1;
            return;
        }
        mp[{u, v}]--;
        if (mp[{u, v}] == 1)
        {
            s.erase({u, v});
        }
        if (mp[{u, v}] == 0)
        {
            cout << -1;
            return;
        }
    }
    cout << -1;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}