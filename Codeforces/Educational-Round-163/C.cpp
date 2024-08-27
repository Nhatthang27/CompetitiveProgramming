
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
    vector<vector<char>> a(2, vector<char>(n + 1));
    fu(i, 0, 1) fu(j, 1, n) cin >> a[i][j];

    auto check1 = [&]() {
        int x = 0, y = 1;
        while (true) {
            while (y < n) {
                if (a[x][y + 1] == '>') {
                    y += 2;
                } else {
                    break;
                }
            }

            x ^= 1;
            if (a[x][y] == '<') {
                return false;
            } else {
                y++;
            }

            while (y < n) {
                if (a[x][y + 1] == '>') {
                    y += 2;
                } else {
                    break;
                }
            }
            if (y == n) {
                return true;
            }

            x ^= 1;
            if (a[x][y] == '<') {
                return false;
            } else {
                y++;
            }
        }
    };

    auto check2 = [&]() {
        int x = 1, y = 2;
        while (true) {
            while (y < n) {
                if (a[x][y + 1] == '>') {
                    y += 2;
                } else {
                    break;
                }
            }
            if (y == n) {
                return true;
            }

            x ^= 1;
            if (a[x][y] == '<') {
                return false;
            } else {
                y++;
            }

            while (y < n) {
                if (a[x][y + 1] == '>') {
                    y += 2;
                } else {
                    break;
                }
            }

            x ^= 1;
            if (a[x][y] == '<') {
                return false;
            } else {
                y++;
            }
        }
    };

    if (check1() || check2()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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