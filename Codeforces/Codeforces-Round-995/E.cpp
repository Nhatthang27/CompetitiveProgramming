
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
    vector<int> a(n + 1), b(n + 1);
    vector<int> price;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        price.push_back(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        price.push_back(b[i]);
    }
    sort(price.begin(), price.end());
    price.resize(unique(price.begin(), price.end()) - price.begin());

    vector<int> b_val;

    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(price.begin(), price.end(), a[i]) - price.begin();
        b[i] = lower_bound(price.begin(), price.end(), b[i]) - price.begin();
        b_val.push_back(b[i]);
    }

    sort(b_val.begin(), b_val.end());
    vector<int> sum(2 * n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        sum[a[i] + 1]++;
        sum[b[i] + 1]--;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        sum[i] += sum[i - 1];
    }

    int res = 0;
    for (int i = 0; i < price.size(); i++)
    {
        if (sum[i] <= k)
        {
            int num = lower_bound(b_val.begin(), b_val.end(), i) - b_val.begin();
            res = max(res, (n - num) * price[i]);
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