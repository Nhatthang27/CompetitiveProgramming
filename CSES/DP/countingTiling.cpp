
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));

    function<void(int, int, int, int)> generate = [&](int cur_mask, int new_mask, int i, int col)
    {
        if (i == n)
        {
            dp[col + 1][new_mask] = (dp[col][cur_mask] + dp[col + 1][new_mask]) % MOD;
            return;
        }
        if ((cur_mask >> i) & 1)
            generate(cur_mask, new_mask, i + 1, col);
        else
        {
            generate(cur_mask, new_mask | (1 << i), i + 1, col);
            if (i + 1 < n && !((cur_mask >> (i + 1)) & 1))
                generate(cur_mask, new_mask, i + 2, col);
        }
    };

    auto print_mask = [&](int mask, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ((mask >> i) & 1);
        }
        cout << endl;
    };

    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (dp[i][mask] == 0)
                continue;
            generate(mask, 0, 0, i);
        }
    }
    cout << dp[m][0] << endl;
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