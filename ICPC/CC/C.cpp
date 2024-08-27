
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(16, 0));
    dp[0][0] = 1;
    fu(i, 1, n) {
        fu(val, 0, 15) {
            if (val >= a[i]) {
                dp[i][val] = dp[i - 1][val] + dp[i - 1][val - a[i]];
            } else {
                dp[i][val] = dp[i - 1][val];
            }
        }
    }
    fu(i, 1, 15) cout << dp[n][i] << " ";
    // cout << dp[15];
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}