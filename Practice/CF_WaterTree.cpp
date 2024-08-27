
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct SegmentTree {
    int n;
    vector<int> ma, lazy;
    SegmentTree(int n) : n(n) {
        ma.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
    }

    void push(int id, int l, int r) {
        if (lazy[id] == -1) return;
        if (l != r) {
            ma[id * 2] = lazy[id * 2] = lazy[id];
            ma[id * 2 + 1] = lazy[id * 2 + 1] = lazy[id];
        }
        lazy[id] = -1;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (r < u || v < l) return;
        if (u <= l && r <= v) {
            ma[id] = lazy[id] = val;
            return;
        }
        push(id, l, r);
        int m = (l + r) / 2;
        update(2 * id, l, m, u, v, val);
        update(2 * id + 1, m + 1, r, u, v, val);
        ma[id] = max(ma[2 * id], ma[2 * id + 1]);
    }

    void update(int u, int v, int val) {
        update(1, 1, n, u, v, val);
    }

    int getMax(int id, int l, int r, int u, int v) {
        if (r < u || v < l) return 0;
        if (u <= l && r <= v) return ma[id];
        push(id, l, r);
        int m = (l + r) / 2;
        return max(getMax(2 * id, l, m, u, v), getMax(2 * id + 1, m + 1, r, u, v));
    }

    int getMax(int u, int v) {
        return getMax(1, 1, n, u, v);
    }
};
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> l(n + 1, 0), r(n + 1, 0);
    vector<int> par(n + 1, 0);
    int tin = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        l[u] = ++tin;
        for (int v : adj[u]) {
            if (v == p) continue;
            par[v] = u;
            dfs(v, u);
        }
        r[u] = tin;
    };
    dfs(1, 0);
    SegmentTree st(n);
    SegmentTree st2(n);
    int q;
    cin >> q;
    fu(i, 1, q) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            st.update(l[x], r[x], i);
        } else if (t == 2) {
            st2.update(l[x], l[x], i);
        } else {
            int water = st.getMax(l[x], l[x]);
            int block = st2.getMax(l[x], r[x]);
            if (water > block) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t-- > 0) {
        solve();
    }
}