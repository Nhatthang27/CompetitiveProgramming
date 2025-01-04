
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
    vector<vector<int>> cost(n + 1, vector<int>(n + 1));
    fu(i, 1, n) fu(j, 1, n) cin >> cost[i][j];

    vector<vector<int>> minCost(n + 1, vector<int>(n + 1, 1e18));
    fu(i, 1, n) fu(j, 1, n) minCost[i][j] = cost[i][j];

    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));
    fu(i, 1, n) fu(j, 1, n) next[i][j] = j;
    // floyd
    fu(k, 1, n) fu(i, 1, n) fu(j, 1, n) {
        if (minCost[i][j] > minCost[i][k] + minCost[k][j]) {
            minCost[i][j] = minCost[i][k] + minCost[k][j];
            next[i][j] = next[i][k];
        }
        if (minCost[i][j] == minCost[i][k] + minCost[k][j]) {
            if (i != k && k != j) {
                next[i][j] = next[i][k];
            }
        }
    }

    fu(u, 1, n - 1) {
        fu(v, u + 1, n) {
            if (minCost[u][v] < cost[u][v]) {
                cout << -1;
                return;
            }
        }
    }

    vector<vector<bool>> chose(n + 1, vector<bool>(n + 1, false));
    fu(u, 1, n - 1) {
        fu(v, u + 1, n) {
            int x = u;
            while (x != v) {
                chose[x][next[x][v]] = true;
                x = next[x][v];
            }
        }
    }
    int res = 0;
    fu(i, 1, n - 1) fu(j, i + 1, n) if (!chose[i][j]) res++;
    cout << res << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}