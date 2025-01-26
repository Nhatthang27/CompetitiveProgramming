
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    int num_zero = 0, num_one = 0;
    int root = 0;
    vector<pair<int, int>> dp(n, {0, 0});
    function<void(int, int)> dfs = [&](int u, int p)
    {
        for (auto [v, dir] : adj[u])
        {
            if (v == p)
                continue;
            num_zero += (dir == 0);
            num_one += (dir == 1);

            dp[v].first += dp[u].first + (dir == 0);
            dp[v].second += dp[u].second + (dir == 1);

            dfs(v, u);
        }
    };
    dfs(root, -1);
    // for (int u = 0; u < n; u++)
    // {
    //     cerr << u + 1 << " " << dp[u].first << " " << dp[u].second << endl;
    // }
    // cerr << num_zero << " " << num_one << endl;
    vector<int> ans(n, 0);
    int res = n - 1;
    for (int u = 0; u < n; u++)
    {
        ans[u] = num_one - dp[u].second + dp[u].first;
        res = min(res, ans[u]);
    }
    cout << res << "\n";
    for (int u = 0; u < n; u++)
    {
        if (ans[u] == res)
        {
            cout << u + 1 << " ";
        }
    }
    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}