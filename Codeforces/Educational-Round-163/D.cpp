
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
    int res = 0;
    for (int len = n / 2; len >= 1; len--) {
        int cnt = 0;
        // cout << len << "\n";
        fu(l, 1, n - len + 1) {
            if (s[l] == s[l + len] || s[l] == '?' || s[l + len] == '?') {
                cnt++;
                if (cnt >= len) {
                    // cout << "res=" << len * 2 << "\n";
                    cout << len * 2 << "\n";
                    return;
                }
            } else {
                cnt = 0;
            }
        }
    }
    cout << 0 << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}