
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
    int n, w1, w2;
    cin >> n >> w1 >> w2;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    vector<int> f(n + 1);
    int one = a[1] * w1;
    f[1] = LONG_LONG_MIN;
    fu(i, 2, n - 3) {
        f[i] = max(f[i - 1], one + a[i] * w2);
        one = max(one, a[i] * w1);
    }
    vector<int> g(n + 1);
    g[n] = LONG_LONG_MIN;
    one = a[n] * w1;
    fd(i, n - 1, 3) {
        g[i] = max(g[i + 1], one + a[i] * w2);
        one = max(one, a[i] * w1);
    }
    int res = LONG_LONG_MIN;
    fu(i, 3, n - 3) {
        res = max(res, f[i - 1] + g[i + 1] + a[i]);
    }
    cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}