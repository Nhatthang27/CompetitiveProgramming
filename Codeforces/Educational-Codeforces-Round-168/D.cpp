
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    vector<vector<int>> adj(n + 1);
    fu(v, 2, n)
    {
        int u;
        cin >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> f(n + 1, LONG_LONG_MAX);
    int res = 0;
    function<void(int, int)> dfs = [&](int u, int p)
    {
        int point = LONG_LONG_MAX;
        for (int v : adj[u])
        {
            if (v != p)
            {
                dfs(v, u);
                point = min(point, f[v]);
            }
        }
        if (u != 1 && adj[u].size() == 1)
        {
            f[u] = a[u];
        }
        else
        {
            if (u == 1)
            {
                res = a[u] + point;
            }
            f[u] = (a[u] >= point ? point : (point + a[u]) / 2);
        }
    };
    dfs(1, 0);
    cout << res << "\n";
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
