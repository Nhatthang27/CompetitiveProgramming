
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
    vector<int> dp(n + 1, LONG_LONG_MAX);
    vector<int> p10(7);
    p10[0] = 1;
    fu(i, 1, 6) p10[i] = p10[i - 1] * 10;

    function<int(int)> cal = [&](int x) {
        if (dp[x] != LONG_LONG_MAX)
            return dp[x];
        if (x < 10)
            return dp[x] = 1;
        fu(i, 0, 6) {
            if (x < p10[i])
                break;
            int dg = x / p10[i] % 10;
            if (dg != 0) {
                dp[x] = min(dp[x], cal(x - dg) + 1);
            }
        }
        return dp[x];
    };
    cout << cal(n);
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}