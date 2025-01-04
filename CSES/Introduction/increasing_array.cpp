
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int mx = 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
        res += mx - x;
    }
    cout << res;
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