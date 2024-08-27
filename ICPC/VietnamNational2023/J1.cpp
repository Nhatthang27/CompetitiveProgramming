
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

void solve() {
    int n;
    cin >> n;

    fu(i, 1, n) {
        int x;
        cin >> x;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[1][1] = 1;

    for (int i = 1; i < n; i++) {
        for (int h = 1; h <= i; h++) {
            if (dp[i][h] == 0) {
                continue;
            }
            for (int k = 1; k <= h; k++) {
                dp[i + 1][k + 1] =
                    (dp[i + 1][k + 1] + 1LL * dp[i][h] * (1LL << (k - 1))) %
                    MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}