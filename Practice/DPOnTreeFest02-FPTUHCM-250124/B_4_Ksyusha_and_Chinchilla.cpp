
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct custom_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 + FIXED_RANDOM + (h2 << 12));
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    unordered_map<pair<int, int>, int, custom_hash> edges_id;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges_id[{u, v}] = edges_id[{v, u}] = i + 1;
    }
    bool ok = true;
    vector<int> res;
    vector<int> dp(n, 0);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        if (!ok)
            return;
        dp[u] = 1;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            dp[u] += dp[v];
        }

        if (dp[u] > 3) // if the number of children of a node is greater than 3 then it is not possible to make a chinchilla
        {
            ok = false;
            return;
        }

        if (u == 0)
        {
            if (dp[u] != 3)
                ok = false;
        }
        else if (dp[u] == 3)
        {
            res.push_back(edges_id[{u, p}]);
            dp[u] = 0;
        }
    };
    dfs(0, -1);
    if (!ok)
    {
        cout << "-1\n";
        return;
    }
    cout << res.size() << '\n';
    for (int x : res)
        cout << x << " ";
    cout << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}