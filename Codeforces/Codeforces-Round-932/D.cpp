
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
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1, 0);
    fu(i, 1, n) cin >> a[i];

    int total = (c + 1) * (c + 1) - c * (c + 1) / 2;
    int cntBoth = 0;
    int cntSum = 0;
    int cntSub = 0;

    fu(i, 1, n) {
        int mid = a[i] / 2 + (a[i] % 2 == 1);
        if (c >= mid) {
            cntSum += min(c, a[i]) - mid + 1;
        }
        if (c >= a[i]) {
            cntSub += (c - a[i] + 1);
        }
    }

    vector<int> odd, even;
    fu(i, 1, n) {
        if (a[i] % 2 == 1) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }

        int mi = a[i] - 2 * c;
        int ma = 2 * c - a[i];
        if (a[i] % 2 == 1) {
            cntBoth += upper_bound(odd.begin(), odd.end(), ma) -
                       lower_bound(odd.begin(), odd.end(), mi);
        } else {
            cntBoth += upper_bound(even.begin(), even.end(), ma) -
                       lower_bound(even.begin(), even.end(), mi);
        }
    }
    cout << total - cntSum - cntSub + cntBoth << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}