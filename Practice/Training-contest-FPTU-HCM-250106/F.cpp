
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> buds;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root_leaf = 0;
    function<bool(int, int)> dfs = [&](int u, int par) -> bool
    {
        // cerr << "ehehe" << "\n";
        if (adj[u].size() == 1 && u != 0)
        {
            return true;
        }
        int cnt = 0;
        for (int v : adj[u])
        {
            if (v == par)
                continue;
            cnt += dfs(v, u);
        }
        // cerr << u + 1 << " " << cnt << "\n";
        if (u == 0)
        {
            root_leaf = cnt;
        }
        else if (cnt > 0)
            buds.push_back(cnt);
        return (cnt == 0);
    };  
    dfs(0, -1);
    int res = root_leaf;
    for (int x : buds)
        res += x - 1;
    cout << res + (root_leaf == 0) << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}