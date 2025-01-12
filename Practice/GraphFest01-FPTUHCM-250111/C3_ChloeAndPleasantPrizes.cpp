
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> value(n);
    for (int &v : value)
    {
        cin >> v;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int, int>> dp(n); // fi: max value of subtree i, se: max value of two subtrees of i
    vector<int> sum(n);
    int res = LONG_LONG_MIN;

    function<void(int, int)> dfs = [&](int u, int p)
    {
        sum[u] = value[u];
        dp[u] = {LONG_LONG_MIN, LONG_LONG_MIN};
        // bool isLeaf = true;
        int fi = LONG_LONG_MIN, se = LONG_LONG_MIN;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            // isLeaf = false;
            sum[u] += sum[v];
            dp[u].first = max(dp[u].first, dp[v].first);
            if (dp[v].first > fi)
            {
                se = fi;
                fi = dp[v].first;
            }
            else if (dp[v].first > se)
            {
                se = dp[v].first;
            }
        }
        // if (!isLeaf)
        // {
        //     res = max(res, sum[u]);
        // }
        dp[u].first = max(dp[u].first, sum[u]);
        if (fi != LONG_LONG_MIN && se != LONG_LONG_MIN)
        {
            dp[u].second = max(fi + se, dp[u].second);
        }
        res = max(res, dp[u].second);
        // cerr << u + 1 << " " << dp[u].first << " " << dp[u].second << "\n";
    };
    dfs(0, -1);
    cout << (res == LONG_LONG_MIN ? "Impossible" : to_string(res)) << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}