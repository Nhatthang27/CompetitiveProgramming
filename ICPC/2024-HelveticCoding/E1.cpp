
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

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> s(m + 1), l(m + 1);
    fu(i, 1, m) cin >> s[i];
    fu(i, 1, m) cin >> l[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    fu(i, 1, m) {
        dp[1][i] = s[1] * (s[i] + l[i]) % MOD;
        dp[1][i] = (dp[1][i] + l[1] * s[i] % MOD) % MOD;
        // cout << dp[1][i] << "\n";
    }
    int res = 0;
    fu(i, 2, n) {
        fu(j, 1, m) {
            fu(k, 1, m) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k] * (s[j] + l[j]) % MOD * s[k] % MOD) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][k] * s[j] % MOD * l[k] % MOD) % MOD;
            }
            // cout << dp[i][j] << "\n";
        }
    }
    fu(i, 1, m) res = (res + dp[n][i]) % MOD;
    cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}