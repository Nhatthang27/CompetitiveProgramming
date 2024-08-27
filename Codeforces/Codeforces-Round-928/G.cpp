#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 2e5 + 7;
const ll INF = 1e18;

ll t;
ll n;
vector<ll> adj[MAX];
char tp[MAX];
ll res;
ll dp[MAX][3];

void enter() {
    cin >> n;
    res = 0;
    fu(i, 1, n) {
        adj[i].clear();
    }
    fu(v, 2, n) {
        ll u;
        cin >> u;
        adj[u].push_back(v);
    }
    fu(i, 1, n) {
        cin >> tp[i];
    }
}

void dfs(ll u) {
    dp[u][0] = INF;
    ll cntC = 0;

    bool isLeaf = true;
    for(ll v : adj[u]) {
        isLeaf = false;
        dfs(v, u);
        cntC += dp[v][0];
    }
    if (tp[u] != 'C') cntC = INF;
    dp[u][0] = min({cntC, dp[u][1] + 1, dp[u][2] + 1});
}

void solve() {
    dfs(1, -1);

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    while(t --> 0) {
        enter();
        solve();
    }
}



