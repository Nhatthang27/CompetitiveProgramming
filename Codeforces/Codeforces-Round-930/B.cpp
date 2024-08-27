
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
    vector<vector<char>> a(3, vector<char>(n + 1, '0'));
    fu(i, 1, 2) { fu(j, 1, n) cin >> a[i][j]; }
    int cnt = 1;
    int row = 1;
    int pos = n;
    string res(1, a[1][1]);

    fu(j, 2, n) {
        if (row == 1) {
            if (a[1][j] > a[2][j - 1]) {
                pos = j - 1;
                j--;
                row++;
            }
        }
        res += a[row][j];
        if (row == 1 && j == n)
            res += a[2][n];
    }
    fd(j, pos, 2) {
        if (a[1][j] == a[2][j - 1])
            cnt++;
        else
            break;
    }
    cout << res << "\n" << cnt << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}