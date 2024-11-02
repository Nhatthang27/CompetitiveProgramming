
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
    vector<int> a(10, 0);
    int sz = 0;
    fu(i, 1, 9) cin >> a[i], sz += a[i];
    a[9] += a[6];
    a[6] = 0;

    vector<int> res(sz + 1, 0);
    int id = 1;
    bool odd = true;
    fd(i, 9, 1)
    {
        fu(j, 1, a[i])
        {
            if (odd)
            {
                res[id] = i;
            }
            else
            {
                res[sz - id + 1] = i;
                id++;
            }
            odd = !odd;
        }
    }
    fu(i, 1, sz) cout << res[i] << " ";
    cout << endl;
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