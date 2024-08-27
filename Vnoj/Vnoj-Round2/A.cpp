
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
    int n, x;
    cin >> n >> x;
    int ma = 0;
    int res = 0;
    vector<int> a(n + 1);
    fu(i, 1, n) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    sort(a.begin() + 1, a.end());
    int mul = 1;

    fu(i, 1, n) {
        if (mul > ma || x > (ma + 1) / mul) {
            cout << n << "\n";
            cout << "mul = " << mul << " ma = " << ma << " x = " << x << "\n";
            return;
        }
        if (x * mul >= a[i]) {
            mul = mul * i;
        } else {
            cout << i - 1 << "\n";
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