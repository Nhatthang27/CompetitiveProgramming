
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<int> sum(n + 1);
    int ans = 10000000000000000;

    fu(i, 0, n - 1) cin >> a[i];
    fu(i, 0, n - 1) cin >> b[i];

    int res = 0;
    for (int i = n - 1; i >= m; --i) {
        res += min(a[i], b[i]);
    }

    for (int i = m - 1; i >= 0; --i) {
        sum[i] = sum[i + 1] + min(a[i], b[i]);
    }

    fu(i, 0, m - 1) { ans = min(ans, sum[i + 1] + a[i] + res); }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}