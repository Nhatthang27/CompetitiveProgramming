
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
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    auto check = [&](int len) {
        fu(l, 1, n - len + 1) {
            int r = l + len - 1;
            int mid = (l + r) / 2;
            bool ok = true;
            fu(i, 1, len / 2) {
                if (s[l + i - 1] != s[mid + i - 1] && s[l + i - 1] != '?' &&
                    s[mid + i - 1] != '?') {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return true;
        }
        return false;
    };
    int l = 2, r = n - n % 2;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        mid = mid - mid % 2;
        cout << mid << "\n";
        if (check(mid)) {

            res = mid;
            l = mid + 2;
        } else {
            r = mid - 2;
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