
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    int a = 0, b = 0, c = 0;
    for (int i = 30; i >= 0 && a <= l; i--)
    {
        int mask = (1LL << i);
        if (mask + a <= r)
        {
            a += mask;
            // if (a > l)
            //     break;
        }
    }

    for (int i = 30; i >= 0 && b <= l; i--)
    {
        int mask = (1LL << i);
        if (mask + b - 1 <= a)
        {
            b += mask;
            // if (b > l)
            //     break;
        }
    }

    while ((l == (b - 1)) || (l == a))
        l++;
    cout << a << " " << b - 1 << " " << l << "\n";
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