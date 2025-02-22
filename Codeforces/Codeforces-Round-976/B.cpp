
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
    int k;
    cin >> k;
    int l = 1, r = 2e18, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (mid - static_cast<int>(sqrt(mid)) < k)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << '\n';
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