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
    vector<int> c(n + 1, 0);
    fu(i, 1, n) cin >> c[i];
    vector<int> dp(x + 1, 1e18);
    sort(c.begin() + 1, c.end());
    dp[0] = 0;
    fu(val, 1, x) {
        fd(i, n, 1) {
            if (val >= c[i]) {
                dp[val] = min(dp[val], dp[val - c[i]] + 1);
            }
        }
    }
    cout << (dp[x] == 1e18 ? -1 : dp[x]);
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}