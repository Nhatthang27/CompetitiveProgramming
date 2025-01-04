
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
    double x, y;
    cin >> x >> y;

    // double max = ;
    double res = 1e18;
    double a = y - x;
    double b = 2 * x - y;
    if (a > 0 && b > 0)
    {
        res = min(res, (a + b) * 2.0);
    }

    a = x / 2;
    b = y - x;
    if (a > 0 && b > 0)
    {
        res = min(res, (a + b) * 2.0);
    }

    a = x / 2;
    b = (y - x / 2) / 2;
    if (a > 0 && b > 0)
    {
        res = min(res, (a + b) * 2.0);
    }

    if (res == 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << fixed << setprecision(4) << res << endl;
    }
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