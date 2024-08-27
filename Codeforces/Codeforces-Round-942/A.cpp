
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
    vector<int> a(n + 1), b(n + 1);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) cin >> b[i];
    int res = 0;
    while (true) {
        bool ok = true;
        fu(i, 1, n) {
            if (a[i] > b[i]) {
                ok = false;
                break;
            }
        }
        if (ok) break;
        a.insert(a.begin() + 1, 1);
        res++;
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