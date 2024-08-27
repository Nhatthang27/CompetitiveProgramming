
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
    int l, r;
    l = 2, r = 999;
    while (l < r)
    {
        int mid = (l + r) / 2;
        cout << "? 1 " << mid << endl;
        int jury;
        cin >> jury;
        if (jury == mid)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << "! " << l << endl;
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