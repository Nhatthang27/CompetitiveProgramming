
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
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) cin >> b[i];
    unordered_map<int, int> mp;
    fu(i, 1, n) mp[a[i]]++;
    int res = 0;
    fu(i, 1, n)
    {
        if (mp[b[i]] > 0)
        {
            res++;
            mp[b[i]]--;
        }
    }
    res = min(res + 1, n);
    cout << res;
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