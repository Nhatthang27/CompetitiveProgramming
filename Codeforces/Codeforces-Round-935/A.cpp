
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
    int a, b, c;
    cin >> a >> b >> c;
    int res = a;

    if (b % 3 == 0) {
        res += b / 3;
        if (c > 0) {
            res += c / 3 + (c % 3 != 0);
        }
    } else {
        int tmp = 3 - b % 3;
        if (tmp > c) {
            cout << -1 << "\n";
            return;
        }
        c -= tmp;
        res += b / 3 + 1;
        if (c > 0) {
            res += c / 3 + (c % 3 != 0);
        }
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