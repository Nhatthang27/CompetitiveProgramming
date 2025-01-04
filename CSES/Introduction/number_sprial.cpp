
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int mx = max(x, y);
    int mn = min(x, y);
    int res = 0;
    if (mx % 2 == 0)
    {
        res = mx * mx - mn + 1;
    }
    else
    {
        res = (mx - 1) * (mx - 1) + mn;
    }
    cout << res << endl;
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