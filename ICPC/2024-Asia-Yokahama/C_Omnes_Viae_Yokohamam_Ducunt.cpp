#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> sig(n);
    for (int &u : sig)
        cin >> u;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, vul;
        cin >> u >> v >> vul;
        u--;
        v--;
        adj[u].push_back({v, vul});
        adj[v].push_back({u, vul});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int yokohama = 0;
    vector<int> dis(n, LONG_LONG_MAX);
    dis[yokohama] = 0;
    q.push({dis[yokohama], yokohama});
    while (!q.empty())
    {
        auto [du, u] = q.top();
        q.pop();

        if (du != dis[u])
            continue;

        for (auto [v, vul] : adj[u])
        {
            if (dis[v] > du + vul)
            {
                dis[v] = du + vul;
                q.push({dis[v], v});
            }
        }
    }
    int sum = 0;
    for (int u = 0; u < n; u++)
    {
        // cerr << u + 1 << " " << dis[u] << "\n";
        sum += sig[u] * dis[u];
    }
    cout << sum << "\n";
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