
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }

    if (c > a && d < b) {
        cout << "NO\n";
    } else if ((c > b || c < a) && (d > b || d < a)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}