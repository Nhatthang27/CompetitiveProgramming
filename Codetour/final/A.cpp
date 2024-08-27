
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int INF = 1e15;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    fu(i, 1, n) cin >> a[i];

    int maxPoint = 0;

    auto isGood = [&](int x)
    {
        pair<bool, int> res = {true, 0};
        fu(i, 2, n)
        {
            if (a[i] * 2 < x)
            {
                res.ff = false;
                res.ss = 0;
                break;
            }
            res.ss += a[i] - (x / 2 + x % 2);
        }
        return res;
    };

    int l = a[1], r = INF;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        auto flag = isGood(mid);
        if (!flag.ff)
        {
            r = mid - 1;
        }
        int x = mid - a[1];
        if (x > flag.ss)
        {
            r = mid - 1;
        }
        if (flag.ff && x <= flag.ss)
        {
            maxPoint = max(maxPoint, x);
            l = mid + 1;
        }
    }
    cout << maxPoint << "\n";
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