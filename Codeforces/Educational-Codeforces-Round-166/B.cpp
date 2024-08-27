
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
    vector<int> a(n + 1, 0), b(n + 2, 0);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n + 1) cin >> b[i];

    vector<pii> vec;
    int res = 0;
    int add = LONG_LONG_MAX;
    fu(i, 1, n) { res += abs(a[i] - b[i]); }
    fu(i, 1, n) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        if (a[i] <= b[n + 1] && b[n + 1] <= b[i]) {
            cout << res + 1 << "\n";
            return;
        }
        add = min(add, min(abs(a[i] - b[n + 1]), abs(b[i] - b[n + 1])));
    }
    cout << res + add + 1 << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}