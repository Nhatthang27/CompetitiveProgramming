#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

vector<vector<ll>> adj;
vector<ll> c;
vector<map<ll, ll>> mp;
ll res;
ll n;

void enter() {
    cin >> n;
    c.assign(n + 1, 0);
    adj.resize(n + 1);
    mp.resize(n + 1);
    fu(i, 1, n) mp[i].clear();
    fu(u, 1, n) adj[u].clear();
    fu(i, 1, n) cin >> c[i];
    fu(i, 1, n - 1) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(ll u, ll par = -1) {
    mp[u][c[u]] = 1;
    for (ll v : adj[u]) {
        if (v != par) {
            dfs(v, u);
            if (mp[u].size() < mp[v].size()) {
                swap(mp[u], mp[v]);
            }
            for (auto p : mp[v]) {
                ll color = p.first;
                ll cnt = p.second;
                res += cnt * mp[u][color];
                mp[u][color] += mp[v][color];
            }
            mp[u][c[u]] = 1;
            mp[v].clear();
        }
    }
}
void solve() {
    res = 0;
    dfs(1);
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        enter();
        solve();
    }
}