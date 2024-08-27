
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int INF = 1e18;
// segment tree get min lazy update
struct SegmentTree {
    int n;
    vector<int> mi, lz;

    SegmentTree(int n) : n(n) {
        mi.assign(4 * n, INF);
        lz.assign(4 * n, INF);
    }

    void push(int id) {
        mi[id * 2 + 1] = min(mi[id * 2 + 1], lz[id]);
        lz[id * 2 + 1] = min(lz[id * 2 + 1], lz[id]);
        mi[id * 2 + 2] = min(mi[id * 2 + 2], lz[id]);
        lz[id * 2 + 2] = min(lz[id * 2 + 2], lz[id]);
        lz[id] = INF;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) return;
        if (u <= l && r <= v) {
            mi[id] = min(mi[id], val);
            lz[id] = min(lz[id], val);
            return;
        }
        push(id);
        int m = (l + r) / 2;
        update(id * 2 + 1, l, m, u, v, val);
        update(id * 2 + 2, m + 1, r, u, v, val);
        mi[id] = min(mi[id * 2 + 1], mi[id * 2 + 2]);
    }

    void update(int u, int v, int val) {
        update(0, 0, n - 1, u, v, val);
    }

    int getMin(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return INF;
        if (u <= l && r <= v) return mi[id];
        push(id);
        int m = (l + r) / 2;
        return min(getMin(id * 2 + 1, l, m, u, v), getMin(id * 2 + 2, m + 1, r, u, v));
    }

    int getMin(int u, int v) {
        return getMin(0, 0, n - 1, u, v);
    }
};
void solve() {
    int n;
    cin >> n;
    SegmentTree st(n + 1);
    st.update(0, 0, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int st_i = st.getMin(i, i);
        // cout << i << " " << st_i << "\n";
        if (st_i == INF) {
            continue;
        }
        if (x > 0) {
            st.update(i + 1, min(i + x, n), st_i + 1);
        }

        // cout << i + 1 << " " << min(i + x, n) << " " << st_i + 1 << "\n\n";
        // cout << "-> " << st.getMin(7, 7) << "\n";
    }
    int ans = st.getMin(n, n);
    if (ans == INF) {
        cout << "CANNOT GET DESTINATION";
    } else {
        cout << ans;
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