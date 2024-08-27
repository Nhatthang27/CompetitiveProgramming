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
    vector<vector<int>> match(n, vector<int>(n, false));
    fu(i, 0, n - 1) {
        fu(j, 0, n - 1) {
            cin >> match[i][j];
        }
    }
    vector<int> dp((1LL << n), 0);
    dp[0] = 1;
    fu(mask, 1, (1LL << n) - 1) {
        int i = __builtin_popcount(mask) - 1;
        fu(j, 0, n - 1) {
            if (match[i][j] && (mask & (1LL << j))) {
                dp[mask] += dp[mask ^ (1LL << j)];
                dp[mask] %= 1000000007;
            }
        }
    }
    cout << dp[(1LL << n) - 1];
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}