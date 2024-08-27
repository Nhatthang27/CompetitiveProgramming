
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
    vector<int> a(n + 1), c(n + 1);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) cin >> c[i];
    int sum = 0;
    fu(i, 1, n) sum += a[i];

    int res = LONG_LONG_MAX;
    fu(i, -1000, 1000) {
        int val = sum / n + i;
        int ans = 0;
        fu(j, 1, n) {
            ans += abs(a[j] - val) * c[j];
        }
        res = min(res, ans);
    }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}