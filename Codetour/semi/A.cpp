
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int k, x, y;
    cin >> k >> x >> y;
    vector<int> a(n + 1, 0);
    fu(i, 1, n)
    {
        cin >> a[i];
    }
    int res = 1e18;
    // dp[i][j] = min cost to reach jth element with i groups
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));
    dp[0][0] = 0;
    fu(i, 1, n)
    {
        int gcd = 0;
        fd(j, i, 1)
        {
            gcd = __gcd(gcd, a[j]);
            int point = (gcd == k ? x : y);
            fu(z, 1, m)
                dp[i][z] = min(dp[i][z], dp[j - 1][z - 1] + point);
        }
    }
    cout << dp[n][m];
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}