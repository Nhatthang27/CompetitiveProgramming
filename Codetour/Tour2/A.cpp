
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
    vector<pii> a(n + 1);
    fu(i, 1, n) {
        cin >> a[i].ff >> a[i].ss;
    }
    vector<int> sum(n + 1, 0);

    sort(a.begin() + 1, a.end(), [&](pii x, pii y) {
        return x.ss < y.ss;
    });

    fu(i, 1, n) {
        sum[i] = sum[i - 1] + a[i].ff;
        // cout << a[i].ff << " " << a[i].ss << "\n";
    }
    while (q-- > 0) {
        int x;
        cin >> x;
        auto it = upper_bound(a.begin() + 1, a.end(), pii(0, x), [&](pii x, pii y) {
            return x.ss < y.ss;
        });

        int pos = it - a.begin();
        // cout << pos << "\n";
        cout << sum[pos - 1] << "\n";
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