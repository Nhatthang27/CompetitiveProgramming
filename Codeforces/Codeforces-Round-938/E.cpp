
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
    vector<char> a(n + 1);
    fu(i, 1, n) cin >> a[i];

    fd(len, 5, 1) {
        bool ok = true;
        set<int> s;
        fu(i, 1, n) {
            int bound = i - len + 1;
            auto it = s.lower_bound(bound);
            int cnt = it == s.end() ? 0 : distance(it, s.end());
            // for (auto x : s) cout << x << " ";
            // cout << "\n";
            // cout << bound << " " << cnt << "\n\n";
            if (a[i] == '0') {
                if (cnt % 2 == 0) {
                    if (i > n - len + 1) {
                        ok = false;
                        break;
                    }
                    s.insert(i);
                }
            } else {
                if (cnt % 2 == 1) {
                    if (i > n - len + 1) {
                        ok = false;
                        break;
                    }
                    s.insert(i);
                }
            }
        }
        if (ok) {
            cout << len << "\n";
            return;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}