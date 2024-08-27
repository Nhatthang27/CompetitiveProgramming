
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    vector<int> dp(n + 1, 0);
    int sum = 0;
    int ma = 0;

    fu(i, 1, n) {
        sum += a[i];
        sum = (sum + MOD) % MOD;
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        ma = max(ma, dp[i]);
    }

    int total = 0;
    fu(i, 1, k) {
        total = (total + ma + MOD) % MOD;
        ma = (ma + ma + MOD) % MOD;
    }
    // cout << total << "\n";
    cout << (sum + total + MOD) % MOD << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}