
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
    set<int> s;
    vector<int> a(n + 1);
    fu(i, 1, n)
    {
        cin >> a[i];
    }
    map<int, int> mp;

    fu(i, 1, n)
    {
        fu(j, i + 1, n)
        {
            mp[abs(a[i] - a[j])]++;
            s.insert(abs(a[i] - a[j]));
        }
    }

    for (auto x : s)
    {
        cout << x << " " << mp[x] << endl;
    }
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