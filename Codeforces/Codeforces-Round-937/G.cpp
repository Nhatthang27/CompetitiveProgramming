
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
    vector<string> g(n + 1), w(n + 1);
    vector<vector<bool>> dp((1 << n), vector<bool>(n + 1, false));

    fu(i, 1, n) cin >> g[i] >> w[i];

    vector<vector<bool>> isAdj(n + 1, vector<bool>(n + 1, false));
    fu(i, 1, n) {
        fu(j, i + 1, n) {
            if (i == j)
                continue;
            if (g[i] == g[j] || w[i] == w[j])
                isAdj[i][j] = isAdj[j][i] = true;
        }
    }

    fu(i, 1, n) dp[(1 << (i - 1))][i] = true;

    fu(mask, 1, (1 << n) - 1) {
        fu(i, 1, n) {
            if ((mask >> (i - 1)) & 1) {
                if (!dp[mask][i])
                    continue;
                fu(j, 1, n) {
                    if ((mask >> (j - 1)) & 1)
                        continue;
                    if (isAdj[i][j]) {
                        dp[mask | (1 << (j - 1))][j] = true;
                    }
                }
            }
        }
    }

    int res = 0;
    fu(mask, 0, (1 << n) - 1) {
        fu(i, 1, n) {
            if (dp[mask][i]) {
                res = max(res, (long long)__builtin_popcount(mask));
                break;
            }
        }
    }
    cout << n - res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}