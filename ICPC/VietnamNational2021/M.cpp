
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
    cout << n + (n - 1) * (n - 1) << "\n";
    vector<vector<int>> cur(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
    x = a + v;
    fu(i, 1, n) cout << i << " ";
    cout << "\n";
    int dem = n + 1;
    fu(i, 1, n - 1) {
        cout << 1 << " ";
        fu(j, 1, n - 1) {
            pre[i][j] = dem++;
            cout << pre[i][j] << " ";
        }
        cout << "\n";
    }

    fu(i, 1, n - 1) {
        cout << 2 << " ";
        int add = 0;
        fu(j, 1, n - 1) {
            cur[i][j] = pre[j][i];
            cout << cur[i][j] << " ";
        }
        cout << "\n";
    }
    swap(cur, pre);
    fu(k, 3, n) {
        fu(i, 1, n - 1) {
            cout << k << " ";
            int x = 1, y = i;
            fu(j, 1, n - 1) {
                cur[i][j] = pre[x][y];
                cout << cur[i][j] << " ";
                x = (x + 1) % n;
                y = (y + 1) % n;
                if (y == 0)
                    y = 1;
            }
            cout << "\n";
        }
        swap(cur, pre);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}