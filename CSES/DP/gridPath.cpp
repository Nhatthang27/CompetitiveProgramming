
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
    vector<vector<char>> grid(n + 1, vector<char>(n + 1));
    fu(i, 1, n) fu(j, 1, n) cin >> grid[i][j];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    if (grid[1][1] == '*') {
        cout << 0;
        return;
    }
    dp[1][1] = 1;
    fu(i, 1, n) fu(j, 1, n) {
        if (grid[i][j] == '*')
            continue;
        if (i > 1)
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;
        if (j > 1)
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % 1000000007;
    }
    cout << dp[n][n];
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}