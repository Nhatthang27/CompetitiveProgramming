
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 22;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];

    vector<int> dp(1 << MAX, -1);
    fu(i, 1, n) dp[a[i]] = a[i];

    fu(i, 0, MAX - 1) {
        fu(mask, 0, (1 << MAX) - 1) {
            dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask]);
        }
    }

    fu(i, 1, n) {
        int x = a[i];
        int y = ((1 << MAX) - 1) ^ x;
        cout << dp[y] << " ";
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