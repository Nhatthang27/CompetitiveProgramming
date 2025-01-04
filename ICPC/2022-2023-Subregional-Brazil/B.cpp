
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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int cnt = 0;
    fu(i, a, b)
    {
        fu(j, c, d)
        {
            fu(k, e, f)
            {
                if ((i ^ j ^ k) == 0)
                    cnt++;
            }
        }
    }
    cout << (b - a + 1) * (d - c + 1) * (f - e + 1) - cnt << endl;
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