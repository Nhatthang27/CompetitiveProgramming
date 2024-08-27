
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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    fu(i, 1, n) fu(j, 1, m) cin >> a[i][j];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, LONG_LONG_MAX));

    vector<int> sum(n + 1, 0);

    fu(i, 1, n) {
        multiset<int> s;
        dp[i][1] = 1 + a[i][1];
        s.insert(dp[i][1]);
        fu(j, 2, m) {
            dp[i][j] = *s.begin() + a[i][j] + 1;
            s.insert(dp[i][j]);
            if (j > d + 1) {
                s.erase(s.find(dp[i][j - d - 1]));
            }
        }
        sum[i] = sum[i - 1] + dp[i][m];
    }
    int res = LONG_LONG_MAX;
    fu(i, k, n) { res = min(res, sum[i] - sum[i - k]); }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}