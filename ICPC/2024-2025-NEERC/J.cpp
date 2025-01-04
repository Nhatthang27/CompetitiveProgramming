#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            cnt++;
    }
    if ((m - cnt) >= (m + 1) / 2)
    {
        for (int u = 1; u <= n; u++)
            cout << u << " ";
    }
    else
    {
        for (int u = n; u >= 1; u--)
            cout << u << " ";
    }
    cout << endl;
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