
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
    vector<int> a(2), b(2);
    fu(i, 0, 1) cin >> a[i];
    fu(i, 0, 1) cin >> b[i];
    int res = 0;
    fu(i, 0, 1)
    {
        fu(j, 0, 1)
        {
            if (a[i] < b[j])
                continue;
            else if (a[i] == b[j])
            {
                res += (a[i ^ 1] > b[j ^ 1]);
            }
            else
            {
                res += (a[i ^ 1] >= b[j ^ 1]);
            }
        }
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