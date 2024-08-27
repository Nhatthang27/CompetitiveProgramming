
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 1e12;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];

    int l = 1, r = MAX;
    int mi = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        fu(i, 1, n) {
            if (a[i] <= mid) cnt += (mid - a[i]);
        }
        if (cnt <= k) {
            mi = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    int cnt = 0;
    fu(i, 1, n) {
        k -= max(0ll, mi - a[i]);
        cnt += (a[i] > mi);
    }
    int res = n * (mi - 1) + 1 + cnt + k;
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