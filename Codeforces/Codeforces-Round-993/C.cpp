
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
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int res = 0;
    int r1 = m, r2 = m;

    res += min(r1, a);
    r1 -= min(r1, a);

    res += min(c, r1);
    c -= min(c, r1);

    res += min(r2, b);
    r2 -= min(r2, b);

    res += min(c, r2);

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