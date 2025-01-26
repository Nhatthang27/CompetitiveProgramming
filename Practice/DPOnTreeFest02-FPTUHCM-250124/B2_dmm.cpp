
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int &x : p)
    {
        cin >> x;
    }
    sort(p.begin(), p.end());
    while (p.size() > n - 1)
    {
        int x = p.back();
        p.pop_back();
        p.back() = (p.back() * x) % MOD;
    }

    if (p.size() < n - 1)
    {
        vector<int> tmp(n - 1 - p.size(), 1);
        for (int x : p)
        {
            tmp.push_back(x);
        }
        p = tmp;
    }

    vector<int> numChild(n, 0);
    vector<int> pathCount(n, 0);
    int res = 0;
    function<void(int, int)> dfs = [&](int u, int p)
    {
        numChild[u] = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            numChild[u] += numChild[v];
        }
        pathCount[u] = numChild[u] * (n - numChild[u]);
    };
    dfs(0, -1);
    sort(pathCount.begin() + 1, pathCount.end());
    for (int i = 1; i < n; i++)
    {
        res = (res + pathCount[i] * p[i - 1] % MOD) % MOD;
    }
    cout << res << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}