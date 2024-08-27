
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1, 0);
    vector<int> d(m + 1, 0);
    vector<int> f(k + 1, 0);
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, m) cin >> d[i];
    fu(i, 1, k) cin >> f[i];

    vector<int> vec;
    fu(i, 2, n) { vec.push_back(a[i] - a[i - 1]); }
    sort(vec.begin(), vec.end());
    if (vec.size() >= 2 && vec[vec.size() - 1] == vec[vec.size() - 2]) {
        cout << vec[vec.size() - 1] << "\n";
        return;
    }
    int mx = vec.back();

    int a1, a2;
    fu(i, 2, n) {
        if (a[i] - a[i - 1] == mx) {
            a1 = a[i - 1];
            a2 = a[i];
            break;
        }
    }

    sort(d.begin() + 1, d.end());
    sort(f.begin() + 1, f.end());
    int res = mx;
    int mid = (a1 + a2) / 2;
    fu(i, 1, m) {
        int fi = lower_bound(f.begin() + 1, f.end(), mid - d[i]) - f.begin();
        if (fi <= k && fi >= 1) {
            int val = d[i] + f[fi];
            if (a2 - val >= 0 && val - a1 >= 0)
                res = min(res, max(a2 - val, val - a1));
        }

        fi = upper_bound(f.begin() + 1, f.end(), mid - d[i]) - f.begin() - 1;
        if (fi <= k && fi >= 1) {
            int val = d[i] + f[fi];
            if (a2 - val >= 0 && val - a1 >= 0)
                res = min(res, max(a2 - val, val - a1));
        }
    }
    for (int x : vec) {
        if (x != mx) {
            res = max(res, x);
        }
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