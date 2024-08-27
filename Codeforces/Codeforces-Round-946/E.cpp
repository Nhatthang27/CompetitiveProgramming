
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int m, x;
    cin >> m >> x;
    int sum_h = 0;
    vector<int> c(m + 1), h(m + 1);
    fu(i, 1, m) {
        cin >> c[i] >> h[i];
        sum_h += h[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(sum_h + 7, -1));
    vector<vector<bool>> vis(m + 1, vector<bool>(sum_h + 7, 0));
    dp[1][0] = x;
    if (c[1] == 0) dp[1][h[1]] = x;

    fu(i, 2, m) {
        fu(j, 0, sum_h) {
            dp[i][j] = dp[i - 1][j];

            if (j >= h[i]) {
                if (dp[i - 1][j - h[i]] < 0) continue;

                if (dp[i - 1][j - h[i]] >= c[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] - c[i]);
                }
            }
        }
        fu(j, 0, sum_h) {
            if (dp[i][j] >= 0) dp[i][j] += x;
        }
    }
    // cout << dp[2][100] << "\n";
    // cout << dp[2][200] << "\n";
    // cout << dp[2][300] << "\n";
    int res = 0;
    fd(i, sum_h, 0) {
        if (dp[m][i] > 0) {
            res = i;
            break;
        }
    }
    cout << res << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}