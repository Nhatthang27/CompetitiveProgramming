
#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> longestDown, diameter;

void enter() {
    cin >> n;
    adj.resize(n + 1);
    longestDown.assign(n + 1, 0);
    longestDown[0] = -1;
    diameter.assign(n + 1, 0);
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void solve() {
    function<int(int, int)> dfs = [&](int u, int par) -> int {
        for (int v : adj[u]) {
            if (v != par) {
                dfs(v, u);
            }
        }
        pii greatest = {0, 0};
        for (int v : adj[u]) {
            if (v != par) {
                if (longestDown[v] > longestDown[greatest.ff]) {
                    greatest.ss = greatest.ff;
                    greatest.ff = v;
                } else if (longestDown[v] > longestDown[greatest.ss]) {
                    greatest.ss = v;
                }
            }
        }
        diameter[u] = longestDown[greatest.ff] + longestDown[greatest.ss] + 2;
        return longestDown[u] = longestDown[greatest.ff] + 1;
    };

    dfs(1, -1);
    int res = 0;
    fu(i, 1, n) res = max(res, diameter[i]);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    solve();
}