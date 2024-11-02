
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
    int b, c, d;
    cin >> b >> c >> d;

    int res = 0, extra = 0;
    for (int i = 0; i < 62; ++i)
    {
        int b_id = (b >> i) & 1;
        int c_id = (c >> i) & 1;
        int d_id = (d >> i) & 1;
        if (b_id == 0 && c_id == 1 && d_id == 1)
            return void(cout << -1 << '\n');
        if (b_id == 0 && c_id == 0 && d_id == 1)
        {
            res |= (1LL << i);
        }
        if (b_id == 1 && c_id == 0 && d_id == 0)
        {
            res |= (1LL << i);
        }
        if (b_id == 1 && c_id == 1 && d_id == 0)
        {
            res |= (1LL << i);
        }
    }
    if ((res | b) - (res & c) != d)
        return void(cout << -1 << '\n');
    cout << res << '\n';
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