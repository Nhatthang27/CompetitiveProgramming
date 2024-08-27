
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX_BIT = 63;
void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << n << "\n";
        return;
    }
    int res = 0;
    int l = max(n - m, (int)0);
    int r = n + m;
    int tmp = l ^ r;

    int right_most = MAX_BIT - __builtin_clzll(tmp);
    int mul = max((1LL << right_most) - 1, (int)0);
    res = r | mul;
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