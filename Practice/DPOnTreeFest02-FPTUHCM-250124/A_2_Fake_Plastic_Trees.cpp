
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> val(n);
    for (int u = 1; u < n; u++)
    {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i].first >> val[i].second;
    }

    //dp[u] = giá trị lớn nhất đạt được ở u với ít lần thay đổi nhất
    vector<int> dp(n, -1);
    int res = 0;
    function<void(int)> dfs = [&](int u)
    {
        int sum = 0;
        for (int v : adj[u])
        {
            dfs(v);
            sum += dp[v];
        }
        if (val[u].first > sum)
        {
            dp[u] = val[u].second;
            res++;
        }
        else
            dp[u] = min(val[u].second, sum);
    };
    dfs(0);
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