#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define MASK(i) (1LL << i)
#define pll pair<ll, ll>
#define ff first
#define ss second

using namespace std;
const ll MAX = 20;
const ll INF = 1LL << 50;

ll numNode, numEdge;
vector<vector<ll>> dis, dp;
void enter() {
    cin >> numNode >> numEdge;
    dis.assign(numNode +  1, vector<ll>(numNode + 1, INF));
    fu(u, 1, numNode) dis[u][u] = 0;
    fu(i, 1, numEdge) {
        ll u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
    }
}

bool getBit(ll mask, ll i, ll n) {
    return (mask >> (n - i)) & 1;
}

void prepare() {
    fu(k, 1, numNode) {
        fu(u, 1, numNode) {
            fu(v, 1, numNode) {
                if (dis[u][v] > dis[u][k] +  dis[k][v]) {
                    dis[u][v] =  dis[u][k] + dis[k][v];
                }
            }
        }
    }
}

void solve() {
    dp.assign(MASK(numNode), vector<ll>(numNode + 1, INF));
    fu(u, 1, numNode) dp[(1 << (numNode - u))][u] = 0;

    fu(mask, 1, MASK(numNode) - 1) {
        fu(u, 1, numNode) {
            if(dp[mask][u] != INF && getBit(mask, u, numNode)) {
                fu(v, 1, numNode) {
                    ll w = dis[u][v];
                    if (w != INF) {
                        ll newMask = mask | (1 << (numNode - v));
                        dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + w);
                    }
                }
            }
        }
    }

    ll res = INF;
    fu(u, 1, numNode) {
        res = min(res, dp[MASK(numNode) - 1][u]);
    }
    if (res == INF) {
        cout << "No";
    } else {
        cout << res;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    prepare();
    solve();
}


