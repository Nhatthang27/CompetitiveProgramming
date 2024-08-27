
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x + 1);
    fu(i, 1, x) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int res = (n - a[x] + a[1] == 2);
    fu(i, 2, x) { res += (a[i] == a[i - 1] + 2); }
    res += x - 2;
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