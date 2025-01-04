
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
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    string target = "1543";
    for (int i = 0; i < (min(n, m) + 1) / 2; ++i) {
        vector<char> v;
        int p = -1;
        for (int j = i; j < m - i; ++j) {
            v.push_back(a[i][j]);
            if (a[i][j] == '1' && p == -1) {
                p = v.size() - 1;
            }
        }
        for (int j = i + 1; j < n - i; ++j) {
            v.push_back(a[j][m - i - 1]);
            if (a[j][m - i - 1] == '1' && p == -1) {
                p = v.size() - 1;
            }
        }
        for (int j = m - i - 2; j >= i; --j) {
            v.push_back(a[n - i - 1][j]);
            if (a[n - i - 1][j] == '1' && p == -1) {
                p = v.size() - 1;
            }
        }
        for (int j = n - i - 2; j > i; --j) {
            v.push_back(a[j][i]);
            if (a[j][i] == '1' && p == -1) {
                p = v.size() - 1;
            }
        }
        int cnt = 0;
        for (int k = 0; k < v.size(); ++k, p = (p + 1) % v.size()) {
            if (v[p] == target[cnt % 4]) {
                ++cnt;
            } else {
                cnt = (v[p] == '1');
            }
            if (cnt == 4) {
                res++;
                cnt = 0;
            }
        }
    }
    cout << res << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}