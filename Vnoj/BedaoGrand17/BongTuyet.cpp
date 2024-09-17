
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
    function<int(int, int)> myPow = [&](int x, int n) {
        // x^n donot use recursive
        int res = 1;
        while (n > 0) {
            if (n & 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    };
    int n;
    cin >> n;
    int ma = sqrt(n) + 1;

    log
    fu(x, 2, ma) {
        int l = 2, r = ma, po = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int tmp = myPow(x, mid + 1) - 1;
            if (tmp == n * (x - 1)) {
                cout << x << ' ' << mid << '\n';
                return;
            }
            if (tmp < n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    cout << -1 << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}