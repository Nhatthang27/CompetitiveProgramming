/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
#define ll int
#define pll pair<ll, ll>
#define pii pair<int, int>
#define db double
#define fi first
#define se second
#define loop_up(i, a, b) for (ll i = a; i <= b; ++i)
#define loop_down(i, a, b) for (ll i = b; i >= a; --i)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define IOFile(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout);
using namespace std;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
ll getSquare(ll x) {
    return x * x;
}
ll numNode, t;

void solve(vector<vector<ll>>& adj) {
    ll root;
    cin >> root;
    vector<bool> save(numNode + 1, false);
    function<bool(ll x, ll par, bool state)> dfs = [&](ll x, ll par, bool state) {
        if (adj[x].size() == 1 && x != root) {
            return state;
        }
        //        bool tmp = false;
        ll isTrue = 0;
        ll isFalse = 0;
        for (ll g : adj[x]) {
            if (g != par) {
                bool tmp = dfs(g, x, !state);
                isTrue += tmp;
                isFalse += !tmp;
            }
        }
        if (state) {
            return (isFalse == 0);
        } else {
            return (isTrue != 0);
        }
    };
    if (!dfs(root, 0, true)) {
        cout << "Ron\n";
    } else {
        cout << "Hermione\n";
    }
}
int main() {
    cin >> numNode >> t;
    vector<vector<ll>> adj(numNode + 1, vector<ll>());
    loop_up(i, 1, numNode - 1) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (t--) {
        solve(adj);
    }
}
