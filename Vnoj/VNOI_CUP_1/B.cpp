
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
    vector<int> a(n + 2), b(n + 2);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) cin >> b[i];

    int base = 0;
    vector<int> x(n + 1);
    fu(i, 1, n) {
        x[i] = a[i] - b[i];
    }
    int res = 0;
    fu(i, 1, n - 1) {
        x[i + 1] += x[i] / 2;
        x[i] %= 2;
    }
    fd(i, n, 1) {
        if (x[i] < 0) {
            cout << "NO\n";
            return;
        }
        if (x[i] > 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}