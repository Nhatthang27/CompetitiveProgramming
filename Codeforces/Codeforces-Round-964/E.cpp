
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e5;
vector<int> sum(MAX + 5);
void solve()
{
    int l, r;
    cin >> l >> r;
    int res = (sum[l] - sum[l - 1]) * 2 + sum[r] - sum[l];
    cout << res << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    auto getLog3 = [&](int x)
    {
        int res = 0;
        while (x >= 1)
        {
            x /= 3;
            res++;
        }
        return res;
    };
    fu(i, 1, MAX)
    {
        sum[i] = sum[i - 1] + getLog3(i);
    }
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}