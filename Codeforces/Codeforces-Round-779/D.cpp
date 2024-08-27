
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
    int l, r;
    cin >> l >> r;
    vector<int> cnt(20, 0);
    fu(i, 1, r - l + 1) {
        int x;
        cin >> x;
        fu(pos, 0, 18) {
            if ((x >> pos) & 1) {
                cnt[pos]++;
            } else {
                cnt[pos]--;
            }
        }
    }
    int res = 0;
    fu(i, 0, 18) {
        if (cnt[i] > 0)
            res |= (1 << i);
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