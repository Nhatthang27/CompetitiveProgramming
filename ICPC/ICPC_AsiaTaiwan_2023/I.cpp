
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
    fu(i, 1, 2 * n) cin >> a[i];
    vector<vector<int>> dp(2 * n + 1, vector<int>(n + 1, 0));
    fu(val, 1, n) dp[0][val] = 1;

    fu(i, 1, 2 * n) {
        if (a[i] == 0) {
            fu(val, 1, n) {
                if (a[i - 1] == val || a[i + 1] == val) continue;
            }
        } else {
            fu(val, 1, n) {
                if (val == a[i]) continue;
                dp[i][val] = (dp[i][val] + dp[i - 1][val]) % MOD;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}