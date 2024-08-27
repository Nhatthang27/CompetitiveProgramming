
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    fu(i, 1, n) fu(j, 1, m) cin >> a[i][j];

    int g = __gcd(a[1][1], a[n][m]);

    auto check = [&](int x) {
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        dp[1][1] = 1;
        fu(i, 1, n) {
            fu(j, 1, m) {
                if (i == 1 && j == 1) continue;
                if (a[i][j] % x != 0) continue;
                if (i > 1 && dp[i - 1][j]) dp[i][j] = 1;
                if (j > 1 && dp[i][j - 1]) dp[i][j] = 1;
            }
        }
        // fu(i, 1, n) {
        //     fu(j, 1, m) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return dp[n][m];
    };
    fd(u, g, 1) {
        // cout << u << "\n";
        if (g % u != 0) continue;
        if (check(u)) {
            cout << u << "\n";
            return;
        }
    }
    // cout << check(g) << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}