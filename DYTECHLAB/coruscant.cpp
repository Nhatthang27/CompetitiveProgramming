
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
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    fu(i, 1, n) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int cnt = 0;
    int res = LONG_LONG_MAX;
    for (auto x : mp) {
        if (x.ss >= k) {
            cout << 0 << '\n';
            return;
        }
        cnt += x.ss;
        if (n - cnt >= k - x.ss) {
            res = min(res, k - x.ss);
        }
    }
    cout << res << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}