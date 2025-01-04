
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MOD = 998244353;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(3, 0)));

    for (int j = 1; j <= k; j++)
    {
        for (int s = 0; s <= 2; s++)
        {
            dp[1][j][s] = 1;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        vector<int> preSum(k + 1);
        for (int s = 0; s <= 2; s++)
            preSum[1] = (preSum[1] + dp[i - 1][1][s]) % MOD;
        for (int j = 2; j <= k; j++)
        {
            for (int s = 0; s <= 2; s++)
            {
                preSum[j] = (preSum[j] + dp[i - 1][j][s]) % MOD;
            }
            preSum[j] = (preSum[j] + preSum[j - 1]) % MOD;
        }

        for (int j = 1; j <= k; j++)
        {
            // =
            dp[i][j][0] = dp[i - 1][j][0];

            // >
            if (j < k)
                dp[i][j][1] = preSum[k] - preSum[j];

            if (j > 1)
                dp[i][j][2] = preSum[j - 1];
        }
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