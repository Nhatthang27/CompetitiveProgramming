
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
    vector<array<int, 3>> a(n + 1);
    fu(i, 1, n)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        // weight intelligence value
    }

    sort(a.begin() + 1, a.end(), [](array<int, 3> x, array<int, 3> y)
         { return x[0] < y[0]; });

    map<int, int> mp;

    // select a list of dogs such that any two of dogs, the weight of the first dog is less than the weight of the second dog and the intelligence of the first dog is less than the intelligence of the second dog.
    // find the maximum sum of the values of the selected dogs.
    for (int i = 1; i <= n; i++)
    {
        int w = a[i][0], id = a[i][1], v = a[i][2];
        auto it = mp.lower_bound(id);
        if (it == mp.begin())
        {
            mp[id] = v;
        }
        else
        {
            it--;
            if (it->second + v > mp[id])
            {
                mp[id] = it->second + v;
            }
        }
    }
    int ans = 0;
    for (auto x : mp)
    {
        ans = max(ans, x.second);
    }
    cout << ans << endl;
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