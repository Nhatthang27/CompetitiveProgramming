
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
    vector<pii> mon(n + 1);
    fu(i, 1, n) {
        cin >> mon[i].ss;
    }
    fu(i, 1, n) {
        cin >> mon[i].ff;
    }
    sort(mon.begin() + 1, mon.end());

    auto getSum = [&](int init, int t, int st) {
        return init * t - (st * (t - 1) + st) * (t - 1) / 2;
    };

    int total = 0;
    fu(i, 1, n) {
        mon[i].ss -= total;
        if (mon[i].ss <= 0) {
            continue;
        }
        if (i > 1)
            k -= mon[i].ff;
        int l = 1, r = k;
        int num = LONG_LONG_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (k < mon[i].ff * (mid - 1)) {
                r = mid - 1;
                continue;
            }
            int sum = getSum(k, mid, mon[i].ff);
            if (sum >= mon[i].ss) {
                num = min(num, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (num == LONG_LONG_MAX) {
            cout << "NO\n";
            return;
        }
        total += getSum(k, num, mon[i].ff);
        k -= mon[i].ff * (num - 1);
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}