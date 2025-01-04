#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
using namespace __gnu_pbds;

typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

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

    indexed_multiset s;
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        int cur_sum = sum - a[i];
        int l = x - cur_sum;
        int r = y - cur_sum;

        res += s.order_of_key({r + 1, 0}) - s.order_of_key({l, 0});

        s.insert({-a[i], i});
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
