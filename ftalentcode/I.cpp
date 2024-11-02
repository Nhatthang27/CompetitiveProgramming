
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
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];

    int res = 0;
    int mi = LONG_LONG_MAX;
    fu(i, 1, n)
    {
        res += (m / a[i]) * (t / m);
        int rem = t % m;
        res += rem / a[i];
        }
    // res -= t / mi;
    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    // cin >> t
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}