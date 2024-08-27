
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

bool getBit(int mask, int i) { return (mask >> i) & 1; }
void solve() {
    int n, limit;
    cin >> n >> limit;
    vector<int> a(n);
    fu(i, 0, n - 1) cin >> a[i];
    vector<pii> dp((1 << n), {n, LONG_LONG_MAX});
    dp[0] = {1, 0};
    for (int mask = 0; mask < (1 << n); mask++) {
        // fu(i, 0, n - 1) { cout << getBit(mask, i); }
        // cout << '\n';
        // cout << dp[mask].ff << " " << dp[mask].ss << "\n\n";
        fu(i, 0, n - 1) {
            if (!getBit(mask, i)) {
                int nMask = mask | (1 << i);
                int nWeight = dp[mask].ss + a[i];
                bool add = (nWeight <= limit ? 0 : 1);
                int newValue = dp[mask].ff + add;
                if (newValue < dp[nMask].ff) {
                    dp[nMask] = {newValue, (add ? a[i] : nWeight)};
                } else if (newValue == dp[nMask].ff) {
                    if (add)
                        dp[nMask].ss = min(dp[nMask].ss, a[i]);
                    else
                        dp[nMask].ss = min(dp[nMask].ss, nWeight);
                }
            }
        }
    }
    // cout << (1 << n) - 1 << '\n';
    cout << dp[(1 << n) - 1].ff;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}