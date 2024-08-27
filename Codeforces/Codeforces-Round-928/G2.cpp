#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 2e5 + 7;

ll t;
ll n;
vector<ll> adj[MAX];
char tp[MAX];
char newTp[MAX];
ll res;

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
        newTp[i] = tp[i];
    }
}

void dfs(ll u) {
    ll nS = 0, nP = 0;
    for(ll v : adj[u]) {
        dfs(v);
        nS += newTp[v] == 'S';
        nP += newTp[v] == 'P';
    }
    if (adj[u].size() > 0) {
        if (tp[u] == 'S') res += nP;
        else if (tp[u] == 'P') res += nS;
        else {
            if (nS > nP) {
                newTp[u] = 'S';
                res += nP;
            } else if (nS < nP){
                newTp[u] = 'P';
                res += nS;
            } else {
                res += nS;
            }
        }
    }
}

void solve() {
    dfs(1);
    cout << res << "\n";
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




