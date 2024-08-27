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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    fu(i, 1, n) cin >> a[i];
    int res = (a[n - k] + a[n]) - (a[k + 1] + a[1]);
    cout << res << "\n";
    vector<bool> vis(n + 1, false);
    fu(i, 1, n)
    {
        if (vis[i] == false)
        {
            cout << i << " " << i + k << "\n";
            vis[i] = vis[i + k] = true;
        }
    }
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