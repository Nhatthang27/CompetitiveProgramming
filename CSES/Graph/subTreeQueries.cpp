
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
    vector<int> st;
    SegmentTree(int n) : n(n) {
        st.assign(4 * n, 0);
    }

    void update(int id, int l, int r, int p, int val) {
        if (l == r) {
            st[id] = val;
        } else {
            int mid = (l + r) / 2;
            if (p <= mid) {
                update(id * 2, l, mid, p, val);
            } else {
                update(id * 2 + 1, mid + 1, r, p, val);
            }
            st[id] = st[id * 2] + st[id * 2 + 1];
        }
    }

    int getSum(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return 0;
        }
        if (u <= l && r <= v) {
            return st[id];
        }
        int mid = (l + r) / 2;
        return getSum(id * 2, l, mid, u, v) + getSum(id * 2 + 1, mid + 1, r, u, v);
    }

    void update(int p, int val) {
        update(1, 1, n, p, val);
    }

    int getSum(int u, int v) {
        return getSum(1, 1, n, u, v);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1);
    fu(i, 1, n) cin >> val[i];

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
    fu(u, 1, n) {
        st.update(l[u], val[u]);
    }
    while (q-- > 0) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, newVal;
            cin >> u >> newVal;
            st.update(l[u], newVal);
        } else {
            int u;
            cin >> u;
            cout << st.getSum(l[u], r[u]) << endl;
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