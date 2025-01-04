
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto isGood = [&](int p)
    {
        int buy = n - (lower_bound(b.begin(), b.end(), p) - b.begin());
        int pos = a.end() - lower_bound(a.begin(), a.end(), p);
        int neg = buy - pos;
        if (neg <= k)
            return p * buy;

        return -1LL;
    };

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = isGood(a[i]);
        if (ans != -1)
            res = max(res, ans);
        ans = isGood(b[i]);
        if (ans != -1)
            res = max(res, ans);
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