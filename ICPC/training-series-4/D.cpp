
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
    int n;
    cin >> n;
    vector<int> ida(n + 1), idb(n + 1);
    fu(i, 1, n)
    {
        int x;
        cin >> x;
        ida[x] = i;
    }
    fu(i, 1, n)
    {
        int x;
        cin >> x;
        idb[x] = i;
    }

    auto getSum = [&](int x) -> int
    {
        return x * (x + 1) / 2;
    };

    int res = 0;
    int l = min(ida[1], idb[1]);
    int r = max(ida[1], idb[1]);
    int t1 = l - 1;
    int t2 = max(r - l - 1, 0ll);
    int t3 = max(n - r, 0ll);
    res += getSum(t1) + getSum(t2) + getSum(t3);
    // cout << res << endl;
    fu(i, 2, n)
    {
        int new_l = min(ida[i], idb[i]);
        int new_r = max(ida[i], idb[i]);

        if (new_r < l)
        {
            res += (n - r + 1) * (l - new_r);
        }
        else if (new_l > r)
        {
            res += l * (new_l - r);
        }
        else if (new_l < l && new_r > r)
        {
            res += (l - new_l) * (new_r - r);
        }
        l = min(l, new_l);
        r = max(r, new_r);
    }
    cout << res + 1 << endl;
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