
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
    vector<int> a(n + m + 2, 0), b(n + m + 2, 0);
    fu(i, 1, m + n + 1) cin >> a[i];
    fu(i, 1, m + n + 1) cin >> b[i];

    vector<int> res(n + m + 1, 0);
    int sum = 0;
    multiset<int> chose1, chose2;
    vector<int> c(n + m + 1, 0);  // c[i] = 1 if a[i] is chosen, c[i] = 2 if b[i] is chosen
    int dn = 0, dm = 0;
    int ma1 = LONG_LONG_MIN, ma2 = LONG_LONG_MIN;
    fu(i, 1, n + m) {
        if (a[i] > b[i]) {
            if (dn < n) {
                c[i] = 1;
                sum += a[i];
                dn++;
            } else {
                ma1 = max(ma1, a[i] - b[i]);
                c[i] = 2;
                sum += b[i];
                dm++;
            }
        } else {
            if (dm < m) {
                c[i] = 2;
                sum += b[i];
                dm++;
            } else {
                ma2 = max(ma2, b[i] - a[i]);
                c[i] = 1;
                sum += a[i];
                dn++;
            }
        }
    }
    fu(i, 1, n + m) {
        int res = sum;
        if (c[i] == 1) {
            res -= a[i];
            res += max(ma1 + b[n + m + 1], a[n + m + 1]);
        } else {
            res -= b[i];
            res += max(ma2 + a[n + m + 1], b[n + m + 1]);
        }
        cout << res << " ";
    }
    cout << sum << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}