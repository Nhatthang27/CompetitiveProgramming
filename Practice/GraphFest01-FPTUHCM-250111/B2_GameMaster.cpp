
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u = a[i][2];
        int v = a[i + 1][2];
        adj[u].push_back(v);
    }
    int ma1 = a.back()[2];

    sort(a.begin(), a.end(), [&](array<int, 3> x, array<int, 3> y)
         { return x[1] < y[1]; });
    for (int i = 0; i < n - 1; i++)
    {
        int u = a[i][2];
        int v = a[i + 1][2];
        adj[u].push_back(v);
    }
    int ma2 = a.back()[2];

    vector<int> ans(n, 0);
    function<void(int)> dfs = [&](int u)
    {
        ans[u] = 1;
        for (int v : adj[u])
        {
            if (ans[v] == 1)
                continue;
            dfs(v);
        }
    };
    // cerr << ma1 << " " << ma2 << endl;
    dfs(ma1);
    dfs(ma2);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
    }
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