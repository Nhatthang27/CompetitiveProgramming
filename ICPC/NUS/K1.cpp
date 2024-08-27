
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
    vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
    int res = 0;
    fu(i, 1, n) {
        if (a[i] % 2 == 0) {
            dp1[i] = dp1[i - 1];
            dp2[i] = dp2[i - 1] + 1;
        } else {
            dp1[i] = dp2[i - 1] + 1;
            dp2[i] = dp1[i - 1];
        }
        res += dp2[i];
    }
    cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}