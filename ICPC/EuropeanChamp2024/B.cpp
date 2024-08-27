
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
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) cin >> b[i];

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    int res = 0;
    fu(t, 1, n) {
        int ans = LONG_LONG_MAX;
        fu(i, 1, n) {
            if (i <= t) {
                ans = min(ans, abs(a[i] - b[n - t + i]));
            } else {
                ans = min(ans, abs(a[i] - b[i - t]));
            }
        }
        res = max(res, ans);
    }
    cout << res << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
