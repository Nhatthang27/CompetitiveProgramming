
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
    vector<vector<double>> kill(n, vector<double>(n, 0));
    fu(i, 0, n - 1) {
        fu(j, 0, n - 1) {
            cin >> kill[i][j];
        }
    }
    vector<double> dp((1LL << n), 0);
    dp[0] = 1;
    for (int mask = 0; mask < (1LL << n) - 1; mask++) {
        for (int i = 0; i < n; i++) {
            int cnt = n - __builtin_popcount(mask);
            if (!((mask >> i) & 1)) {
                for (int j = 0; j < n; j++) {
                    if (j != i && !((mask >> j) & 1)) {
                        dp[mask | (1LL << j)] += dp[mask] * kill[i][j] * 2.0 / (cnt * (cnt - 1));
                    }
                }
            }
        }
    }
    int mask = (1LL << n) - 1;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(6);
        cout << dp[mask ^ (1LL << i)] << " ";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}