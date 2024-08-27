
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
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    fu(i, 2, n - 1) {
        int k = a[i] / 2;
        k = min({k, a[i - 1], a[i + 1]});
        a[i] = a[i] - 2 * k;
        a[i - 1] -= k;
        a[i + 1] -= k;
    }
    fu(i, 1, n) {
        if (a[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}