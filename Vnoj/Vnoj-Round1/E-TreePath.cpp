#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MASK(i) (1LL << i)

using namespace std;
const ll MAX = 1e5 + 7;
const ll INF = 1e18;

ll numNode, numEdge;
vector<pll> adj[MAX];
ll cnt[MAX];
ll res;
ll a[MAX];

void enter() {
    cin >> numNode;
    numEdge = numNode - 1;
    fu(i, 1, numEdge) {
        ll u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        if (u + 1 == v) {
            a[u] = w;
        }
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
}

set<ll> path;

void dfs(ll root, ll u, ll par) {
    for(pll cc : adj[u]) {
        ll v = cc.ff;
        ll w = cc.ss;
        if (v != par) {
            path.insert(w);
            cnt[w]++;
            if (v > root) {
                for(ll linh : path) {
                    if (cnt[linh] >= 2) res += cnt[linh];
                }
            }

            dfs(root, v, u);
            cnt[w]--;
            if(cnt[w] == 0) {
                path.erase(w);
            }
        }
    }
}

void solve() {
    fu(u, 1, numNode) {
        memset(cnt, 0, sizeof(cnt));
        path.clear();
        dfs(u, u, -1);
    }
    cout << res;
}

ll cnt2[MAX];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    if (n <= 300) {
        solve();
    } else {
        memset(cnt2, 0, sizeof(cnt2));
        fu(i, 1, numNode - 1) {
            cnt2[a[i]]++;
        }

    }

}







