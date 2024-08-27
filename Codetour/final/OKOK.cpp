
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
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, 0)));

    dp[n - 1][2][1] = 1;
    if (s[n - 1] == 'O')
    {
        dp[n - 1][0][1] = 1;
    }
    else
    {
        dp[n - 1][1][1] = 1;
    }

    fd(i, n - 2, 0)
    {
        if (s[i] == 'O')
        {
            dp[i][2][0] = (dp[i + 1][2][0] + dp[i + 1][1][0]) % MOD;
            dp[i][2][1] = (dp[i + 1][2][1] + dp[i + 1][1][1]) % MOD;

            dp[i][0][0] = (dp[i + 1][2][0] + dp[i + 1][0][0]) % MOD;
            dp[i][0][1] = (dp[i + 1][2][1] + dp[i + 1][0][1]) % MOD;

            dp[i][1][0] = dp[i + 1][1][0];
            dp[i][1][1] = dp[i + 1][1][1];
        }
        else
        {
            dp[i][2][0] = (dp[i + 1][2][0] + dp[i + 1][0][1]) % MOD;
            dp[i][2][1] = (dp[i + 1][2][1] + dp[i + 1][0][0]) % MOD;

            dp[i][1][0] = (dp[i + 1][2][0] + dp[i + 1][1][0]) % MOD;
            dp[i][1][1] = (dp[i + 1][2][1] + dp[i + 1][1][1]) % MOD;

            dp[i][0][0] = dp[i + 1][0][0];
            dp[i][0][1] = dp[i + 1][0][1];
        }
    }
    cout << dp[0][2][1] << "\n";
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