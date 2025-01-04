
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
    fu(i, 1, n) {
        cin >> a[i];
    }

    auto check = [&](int s) -> bool {
        int add = 0;
        fu(i, 1, n) {
            int task = a[i] + add;
            if (task <= s) {
                add = 0;
                continue;
            };
            int y = (task - s);
            int x = s - y;
            if (x < 0 || y < 0) return false;
            add = task - x;
        }
        return (add == 0);
    };

    int l = 0, r = *max_element(a.begin(), a.end());
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}