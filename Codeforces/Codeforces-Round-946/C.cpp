
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
    int x, y;
    cin >> x >> y;
    int res = (y + 1) / 2;
    int cell = res * 5 * 3 - y * 4;
    res += max(0ll, x - cell) / 15;
    if (x - cell > 0 && (x - cell) % 15 != 0) res++;
    cout << res << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}