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
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    fu(i, 1, n) {
        fu(j, 1, n) {
            int x;
            cin >> x;
            adj[i][j] = x;
        }
    }

    fu(i, 1, n) {
        fu(j, 1, n) {
            if (adj[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}