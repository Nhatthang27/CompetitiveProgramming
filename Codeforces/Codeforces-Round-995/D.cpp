
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    int sum = 0;
    fu(i, 1, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin() + 1, a.end());

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur_sum = sum - a[i];
        // x <= cur_sum - a[j] <= y (j < i)
        // x - cur_sum <= -a[j] <= y - cur_sum
        // cur_sum - y <= a[j] <= cur_sum - x
        int left = lower_bound(a.begin() + 1, a.begin() + i, cur_sum - y) - a.begin() - 1;  // -7
        int right = upper_bound(a.begin() + 1, a.begin() + i, cur_sum - x) - a.begin() - 1; // -3
        res += right - left;
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