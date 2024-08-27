
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
    int sum = 0;
    fu(i, 1, n) {
        sum += s[i] - '0';
    }
    int cur = 0;
    fu(i, 1, n) {
        cur += s[i] - '0';
        if (s[i] == '0') {
            if (cur == sum) {
                if (i == n) {
                                }
            }
        }
    }
    fu(i, 1, n - 1) {
        if (s[i] == '1' && s[i + 1] == '0') {
            res++;
        }
        if (s[i] == '0' && s[i + 1] == '1') {
            res++;
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