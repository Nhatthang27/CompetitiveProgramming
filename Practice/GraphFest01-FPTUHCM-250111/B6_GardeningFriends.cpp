
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, c;
    cin >> n >> k >> c;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int, vector<int> &)> bfs = [&](int root, vector<int> &d)
    {
        queue<int> q;
        q.push(root);
        d[root] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    };

    vector<int> d(n, -1);
    vector<int> d1(n, -1);
    vector<int> d2(n, -1);
    bfs(0, d);
    int leaf1 = max_element(d.begin(), d.end()) - d.begin();

    bfs(leaf1, d1);
    int leaf2 = max_element(d1.begin(), d1.end()) - d1.begin();

    bfs(leaf2, d2);
    int res = 0;
    for (int u = 0; u < n; u++)
    {
        res = max(res, max(d1[u], d2[u]) * k - d[u] * c);
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