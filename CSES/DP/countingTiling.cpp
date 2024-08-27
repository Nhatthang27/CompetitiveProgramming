
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>((1 << 10) + 1, 0));
    vector<int> sum(m + 1, 0);

    dp[0][0] = 1;
    sum[0] = 1;
    if (n % 2 == 0)
        dp[1][0] = 1, sum[1] = 1;
    fu(i, 2, m) {
        fu(mask, 0, (1 << n) - 1) {}
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