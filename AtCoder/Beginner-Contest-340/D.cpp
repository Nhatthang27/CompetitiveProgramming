#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 2e5 + 7;
const ll INF = 1e18;

ll n, a[MAX], b[MAX], x[MAX];
ll dp[MAX];

struct Type {
    ll node, w;
    Type () {}
    Type (ll _node, ll _w) {
        node = _node;
        w = _w;
    }

    bool operator < (const Type& other) const  {
        return other.w < w;
    }
};

void enter() {
    cin >> n;
    fu(i, 1, n - 1) {
        cin >> a[i] >> b[i] >> x[i];
    }
}

void solve() {
    fu(i, 1, n) dp[i] = INF;
    dp[1] = 0;
    priority_queue<Type> q;
    q.push(Type(1, 0));
    while(!q.empty()) {
        Type cur = q.top();
        q.pop();
        ll u = cur.node;
        ll v1 = u + 1;
        ll v2 = x[u];
        if (dp[v1] > dp[u] + a[u]) {
            dp[v1] = dp[u] + a[u];
            q.push(Type(v1, dp[v1]));
        }
        if (dp[v2] > dp[u] + b[u]) {
            dp[v2] = dp[u] + b[u];
            q.push(Type(v2, dp[v2]));
        }
    }
    cout << dp[n];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    solve();
}



