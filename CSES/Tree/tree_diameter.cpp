
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
vector<int> down, up;

void enter() {
    cin >> n;
    adj.resize(n + 1);
    down.assign(n + 1, 0);
    down[0] = -1;
    up.assign(n + 1, 0);
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void solve() {
    function<void(int, int)> dfs1 = [&](int u, int par) {
        for (int v : adj[u]) {
            if (v != par) {
                dfs1(v, u);
                down[u] = max(down[u], down[v] + 1);
            }
        }
    };
    dfs1(1, -1);

    function<void(int, int)> dfs2 = [&](int u, int par) {
        pii greatest = {0, 0};
        for (int v : adj[u]) {
            if (v != par) {
                if (down[v] > down[greatest.ff]) {
                    greatest.ss = greatest.ff;
                    greatest.ff = v;
                } else if (down[v] > down[greatest.ss]) {
                    greatest.ss = v;
                }
            }
        }

        for (int v : adj[u]) {
            if (v != par) {
                up[v] = max(
                    up[u] + 1,
                    down[(v == greatest.ff ? greatest.ss : greatest.ff)] + 2);
                dfs2(v, u);
            }
        }
    };
    dfs2(1, -1);
    int res = 0;
    fu(i, 1, n) res = max(res, down[i] + up[i]);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    solve();
}