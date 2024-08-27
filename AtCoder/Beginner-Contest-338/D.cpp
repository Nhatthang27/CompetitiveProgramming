#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 2e5 + 7;

ll a[MAX], n, m;
ll path[MAX];

void enter() {
    cin >> n >> m;
    fu(i, 1, n) {
        cin >> path[i];
    }
}

void add(ll u, ll v, ll len) {
    if (u < v) {
        a[u] += len;
        a[v] -= len;
    } else {
        a[u] += len;
        a[n + 1] -= len;
        a[1] += len;
        a[v] -= len;
    }
}

int getDist(ll u, ll v) {
    if (u < v) return v - u;
    else {
        return n - u + v;
    }
}

void solve() {
    fu(i, 1, m - 1) {
        ll u = path[i];
        ll v = path[i + 1];
        add(u, v, getDist(v, u));
        add(v, u, getDist(u, v));
    }
    ll res = 1LL << 60;
    fu(i, 1, n) {
        a[i + 1] += a[i];
        res = min(res, a[i]);
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    solve();
}
