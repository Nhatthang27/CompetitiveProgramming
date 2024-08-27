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
    vector<pii> a(n + 1);
    fu(i, 1, n) cin >> a[i].ff >> a[i].ss;
    sort(a.begin() + 1, a.end(), [](pii x, pii y) {
        return x.ss < y.ss;
    });
    vector<int> dp(n + 1, LONG_LONG_MIN);
    multiset<int> s;
    fu(i, 1, n) {
        int sum = a[i].ff;
        dp[1] = max(dp[1], sum - a[i].ss);
        int cnt = 2;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            sum += *it;
            dp[cnt] = max(dp[cnt], sum - a[i].ss);
            cnt++;
        }
        s.insert(a[i].ff);
    }
    fu(i, 1, n) cout << dp[i] << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}