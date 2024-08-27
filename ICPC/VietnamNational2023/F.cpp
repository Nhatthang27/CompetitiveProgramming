
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
    vector<int> cnt_r(n + 1, 0), cnt_p(n + 1, 0), cnt_s(n + 1, 0);

    vector<int> g;
    fu(i, 1, n) {
        cnt_r[i] = cnt_r[i - 1] + (s[i] == 'R');
        cnt_p[i] = cnt_p[i - 1] + (s[i] == 'P');
        cnt_s[i] = cnt_s[i - 1] + (s[i] == 'S');
    }
    pii res = {0, 0};
    fu(len, 2, n) {
        int win = 0;
        for (int l = 1; l <= n; l += len) {
            int r = min(l + len - 1, n);
            int win_r = cnt_r[r] - cnt_r[l - 1];
            int win_p = cnt_p[r] - cnt_p[l - 1];
            int win_s = cnt_s[r] - cnt_s[l - 1];
            win += max({win_r, win_p, win_s});
        }
        if (win >= res.ff) {
            res = {win, len};
        }
    }
    cout << res.ss << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}