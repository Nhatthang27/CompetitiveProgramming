
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
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
    while (p.size() < n - 1)
    {
        p.push_back(1);
    }

    reverse(p.begin(), p.begin() + min(m, n - 1));

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
    sort(pathCount.begin() + 1, pathCount.end(), greater<int>());
    for (int i = 1; i < n; i++)
    {
        // cerr << p[i - 1] << " ";
        res = (res + pathCount[i] * p[i - 1]) % MOD;
    }
    cout << res % MOD << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}