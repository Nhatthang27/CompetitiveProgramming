
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
    int r, p, s;
    int n;
    cin >> n;
    r = p = s = 0;
    fu(i, 1, n) {
        char c;
        cin >> c;
        if (c == 'R') r++;
        if (c == 'P') p++;
        if (c == 'S') s++;
    }
    int res = 0;
    fu(i, 1, n) {
        char c;
        cin >> c;
        if (c == 'R') {
            if (p > 0) {
                res++;
                p--;
            } else if (r > 0) {
                r--;
            } else {
                res--;
            }
        } else if (c == 'P') {
            if (s > 0) {
                res++;
                s--;
            } else if (p > 0) {
                p--;
            } else {
                res--;
            }
        } else {
            if (r > 0) {
                res++;
                r--;
            } else if (s > 0) {
                s--;
            } else {
                res--;
            }
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