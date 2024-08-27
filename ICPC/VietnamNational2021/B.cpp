
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    fu(i, 1, n) fu(j, 1, m) {
        char x;
        cin >> x;
        a[i][j] = x - 'A';
    }
    int res = 0;
    fu(i, 1, n / 2) {
        fu(j, 1, m / 2) {
            int t_left = a[i][j];
            int t_right = a[i][m - j + 1];
            int b_left = a[n - i + 1][j];
            int b_right = a[n - i + 1][m - j + 1];
            int tmp = LONG_LONG_MAX;
            fu(z, 0, 25) {
                int t = 0;
                t += min(abs(t_left - z), 26 - abs(t_left - z));
                t += min(abs(t_right - z), 26 - abs(t_right - z));
                t += min(abs(b_left - z), 26 - abs(b_left - z));
                t += min(abs(b_right - z), 26 - abs(b_right - z));
                tmp = min(tmp, t);
            }
            res += tmp;
        }
    }
    if (m % 2 == 1) {
        fu(i, 1, n / 2) {
            int t = 0;
            int top = a[i][m / 2 + 1];
            int bot = a[n - i + 1][m / 2 + 1];
            int tmp = LONG_LONG_MAX;
            fu(z, 0, 25) {
                int t = 0;
                t += min(abs(top - z), 26 - abs(top - z));
                t += min(abs(bot - z), 26 - abs(bot - z));
                tmp = min(tmp, t);
            }
            res += tmp;
        }
    }
    if (n % 2 == 1) {
        fu(j, 1, m / 2) {
            int t = 0;
            int left = a[n / 2 + 1][j];
            int right = a[n / 2 + 1][m - j + 1];
            int tmp = LONG_LONG_MAX;
            fu(z, 0, 25) {
                int t = 0;
                t += min(abs(left - z), 26 - abs(left - z));
                t += min(abs(right - z), 26 - abs(right - z));
                tmp = min(tmp, t);
            }
            res += tmp;
        }
    }
    cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}