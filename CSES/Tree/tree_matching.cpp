#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
ll n;
vector<vector<ll>> adj(n + 1);

void enter() {
    cin >> n;
    adj.assign(n + 1, vector<ll>());
    fu(i, 1, n - 1) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void solve() {
    vector<ll> dp[2];
    fu(i, 0, 1) dp[i].assign(n + 1, 0);

    function<void(ll, ll)> dfs;

    dfs = [&](ll u, ll par) {
        ll sum = 0;
        for (ll v : adj[u]) {
            if (v != par) {
                dfs(v, u);
                sum += max(dp[0][v], dp[1][v]);
            }
        }
        for (ll v : adj[u]) {
            if (v != par) {
                dp[1][u] =
                    max(dp[1][u], sum - max(dp[0][v], dp[1][v]) + dp[0][v] + 1);
            }
        }
        dp[0][u] = sum;
    };
    dfs(1, -1);

    // fu(u, 1, n) { cout << u << " " << dp[0][u] << " " << dp[1][u] << endl; }

    cout << max(dp[0][1], dp[1][1]);
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    solve();
}