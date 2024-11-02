
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
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int mutual = 0;
    fu(i, 0, min(n, m) - 1)
    {
        if (a[i] == b[i])
            mutual++;
        else
            break;
    }
    int res = n + m - mutual;
    if (mutual != 0)
        res++;
    cout << res << endl;
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