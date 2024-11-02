
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
    vector<int> gas(n + 1);
    fu(i, 1, n)
    {
        cin >> gas[i];
    }

    vector<vector<pii>> adj(n + 1);
    fu(i, 1, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> down(n + 1, 0);

    function<void(int, int)> dfsDown = [&](int u, int p) -> void
    {
        down[u] = gas[u];
        for (auto [v, w] : adj[u])
        {
            if (v == p)
            {
                continue;
            }
            dfsDown(v, u);
            down[u] = max(down[u], down[v] - w + gas[u]);
        }
    };
    dfsDown(1, 0);
    // fu(u, 1, n) cout << u << " " << down[u] << endl;

    // cout << "-------------------" << endl;

    vector<int> up(n + 1, 0);
    up[1] = gas[1];
    int res = max(up[1] + down[1] - gas[1], 0ll);
    function<void(int, int)> dfsUp = [&](int u, int p) -> void
    {
        int mx1 = 0, mx2 = 0;
        for (auto [v, w] : adj[u])
        {
            if (v == p)
            {
                continue;
            }
            if (mx1 < down[v] - w + gas[u])
            {
                mx2 = mx1;
                mx1 = down[v] - w + gas[u];
            }
            else if (mx2 < down[v] - w + gas[u])
            {
                mx2 = down[v] - w + gas[u];
            }
        }
        // cout << u << " " << mx1 << " " << mx2 << endl;
        for (auto [v, w] : adj[u])
        {
            if (v == p)
            {
                continue;
            }
            up[v] = max(up[u], (down[v] - w + gas[u] == mx1 ? mx2 : mx1)) - w + gas[v];
            up[v] = max(up[v], gas[v]);
            dfsUp(v, u);
        }
        res = max(res, up[u] + down[u] - gas[u]);
    };
    dfsUp(1, 0);
    // fu(u, 1, n) cout << u << " " << up[u] << endl;
    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}