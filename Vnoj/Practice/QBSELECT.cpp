
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
    int n;
    cin >> n;
    int res = LONG_LONG_MIN;
    vector<vector<int>> a(5, vector<int>(n + 1));
    fu(i, 1, 4) fu(j, 1, n) cin >> a[i][j], res = max(res, a[i][j]);
    vector<vector<int>> dp(16, vector<int>(n + 1, LONG_LONG_MIN));

    if (res <= 0) {
        cout << res;
        return;
    }
    fu(mask, 0, 15) {
        dp[mask][1] = 0;
        fu(i, 1, 4) {
            if (mask & (1 << (i - 1))) {
                if (i == 1 || !(mask & (1 << (i - 2))))
                    dp[mask][1] += a[i][1];
                else {
                    dp[mask][1] = LONG_LONG_MIN;
                    break;
                }
            }
        }
    }
    fu(j, 2, n) {
        fu(mask, 0, 15) {
            fu(prev_mask, 0, 15) {
                bool ok = true;
                int sum = 0;
                fu(i, 1, 4) {
                    if (mask & (1 << (i - 1))) {
                        sum += a[i][j];
                        if (prev_mask & (1 << (i - 1)) ||
                            (i > 1 && (mask & (1 << (i - 2))))) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok && dp[prev_mask][j - 1] != LONG_LONG_MIN) {
                    dp[mask][j] = max(dp[mask][j], dp[prev_mask][j - 1] + sum);
                }
            }
        }
    }
    fu(mask, 0, 15) { res = max(res, dp[mask][n]); }
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