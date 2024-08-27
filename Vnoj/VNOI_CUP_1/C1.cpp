
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
    int x;
    cin >> x;
    fd(n, 62, 1) {
        if ((1LL << n) - 2 <= x) {
            cout << n << "\n";
            fu(i, 1, n) {
                int x = (1LL << (n - 1)) - 1;
                x ^= (1LL << (n - i));
                cout << x << " ";
            }
            return;
        }
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