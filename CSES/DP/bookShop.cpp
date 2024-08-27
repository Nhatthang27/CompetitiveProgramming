
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
    int n, x;
    cin >> n >> x;
    vector<int> h(n + 1), s(n + 1);
    fu(i, 1, n) cin >> h[i];
    fu(i, 1, n) cin >> s[i];
    vector<vector<int>> dp(2, vector<int>(x + 1, 0));
    fu(i, 1, n) {
        dp[1].assign(x + 1, 0);
        fu(j, 1, x) {
            if (j < h[i])
                dp[1][j] = dp[0][j];
            else
                dp[1][j] = max(dp[0][j], dp[0][j - h[i]] + s[i]);
        }
        copy(dp[1].begin(), dp[1].end(), dp[0].begin());
    }
    cout << dp[1][x];
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}