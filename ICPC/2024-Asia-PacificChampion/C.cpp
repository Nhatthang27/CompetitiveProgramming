
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
    vector<int> a(n + 1, 0);
    fu(i, 1, n) cin >> a[i];
    vector<int> p;
    p.push_back(1);
    fu(i, 2, n) {
        if (a[i] < a[i - 1]) {
            p.push_back(i);
        }
    }
    fu(x, 1, 500000 - n + 1) {
        bool flag = true;
        for (int cc : p) {
            if (__builtin_popcount(x + cc - 1) != __builtin_popcount(a[cc])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << x << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}