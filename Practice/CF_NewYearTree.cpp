
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
    vector<int> st, lazy;

    SegmentTree(int n) : n(n) {
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int id, int l, int r) {
        if (lazy[id] == 0) {
            return;
        }
        st[id] = lazy[id];
        if (l < r) {
            lazy[id * 2] = lazy[id];
            lazy[id * 2 + 1] = lazy[id];
        }
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        push(id, l, r);
        if (v < l || r < u) {
            return;
        }
        if (u <= l && r <= v) {
            lazy[id] = val;
            push(id, l, r);
            // cout << l << " " << r << " " << st[id] << '\n';
        } else {
            int mid = (l + r) / 2;
            update(id * 2, l, mid, u, v, val);
            update(id * 2 + 1, mid + 1, r, u, v, val);
            st[id] = (st[id * 2] | st[id * 2 + 1]);
        }
    }

    int get(int id, int l, int r, int u, int v) {
        push(id, l, r);
        if (v < l || r < u) {
            return 0;
        }
        if (u <= l && r <= v) {
            // cout << "here -> " << l << " " << r << " " << id << " " << st[id] << '\n';
            return st[id];
        }
        int mid = (l + r) / 2;
        return (get(id * 2, l, mid, u, v) | get(id * 2 + 1, mid + 1, r, u, v));
    }

    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    int get(int u, int v) {
        return get(1, 1, n, u, v);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> color(n + 1);
    fu(i, 1, n) cin >> color[i];
    vector<vector<int>> adj(n + 1);
    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> l(n + 1), r(n + 1);
    int tin = 0;
    function<void(int)> dfs = [&](int u) {
        tin++;
        l[u] = tin;
        for (int v : adj[u]) {
            if (l[v] == 0) {
                dfs(v);
            }
        }
        r[u] = tin;
    };
    dfs(1);
    SegmentTree st(n);
    fu(i, 1, n) {
        // cout << i << " " << l[i] << " " << color[i] << "\n";
        st.update(l[i], l[i], 1LL << color[i]);
        // cout << i << " " << l[i] << " " << r[i] << '\n';
    }
    // cout << st.get(1, 1) << '\n';
    // fu(u, 1, n) {
    //     cout << u << " " << st.get(u, u) << '\n';
    // }
    while (q-- > 0) {
        int type;
        cin >> type;
        if (type == 2) {
            int u;
            cin >> u;
            int ans = st.get(l[u], r[u]);
            cout << __builtin_popcountll(ans) << '\n';
        } else {
            int u, c;
            cin >> u >> c;
            st.update(l[u], r[u], 1LL << c);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}