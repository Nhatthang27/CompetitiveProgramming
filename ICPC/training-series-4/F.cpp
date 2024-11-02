
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    vector<int> val(n + 1);

    int goal = 0;

    fu(i, 1, n)
    {
        cin >> val[i];
        goal ^= val[i];
    }
    // cout << goal << endl;
    fu(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (goal == 0)
    {
        cout << "YES\n";
        return;
    }

    int cnt = 0;
    function<void(int, int)> dfs = [&](int u, int p) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p)
            {
                continue;
            }
            dfs(v, u);
            val[u] ^= val[v];
        }
        // cout << u << " " << val[u] << endl;

        if (val[u] == goal)
        {
            cnt++;
            val[u] = 0;
        }
    };

    dfs(1, -1);
    if (cnt >= 3 && k >= 3)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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