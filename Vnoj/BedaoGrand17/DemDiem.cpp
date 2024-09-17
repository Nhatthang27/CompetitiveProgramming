
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
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    fu(i, 0, n - 1) {
        int x, y, w;
        cin >> x >> y >> w;
        a[i] = {(x * x + y * y), w};
    }
    sort(a.begin(), a.end());
    fu(i, 1, n - 1) {
        a[i].ss += a[i - 1].ss;
    }
    while (q-- > 0) {
        int r;
        cin >> r;
        int id = upper_bound(a.begin(), a.end(), make_pair(r * r, LONG_LONG_MAX)) - a.begin() - 1;
        if (id < 0) {
            cout << 0 << '\n';
        } else
            cout << a[id].ss << '\n';
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