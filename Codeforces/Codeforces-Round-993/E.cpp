
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
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    int mul = 1;
    int res = 0;
    while (mul <= r2)
    {
        int l = l1, r = r1;
        int be = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mid * mul <= r2)
            {
                l = mid + 1;
                be = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        l = l1, r = r1;
        int fe = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mid * mul >= l2)
            {
                r = mid - 1;
                fe = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        // cout << mul << " " << fe << " " << be << "\n";
        if (fe != -1 && be != -1)
        {
            res += (be - fe + 1);
        }
        mul *= k;
    }
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