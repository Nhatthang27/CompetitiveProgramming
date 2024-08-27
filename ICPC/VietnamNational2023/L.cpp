
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
    struct Node {
        int val, sz;
        Node(int _val = 0, int _sz = 0) {
            val = _val;
            sz = _sz;
        }
    };

    vector<Node> tree;
    int n;
    SegmentTree(int _n) {
        n = _n;
        tree.assign(4 * n, Node());
    }

    void update(int id, int l, int r, int i, int val) {
        if (i < l || i > r)
            return;
        if (l == r) {
            tree[id] = Node(tree[id].val + val, 1);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, i, val);
        update(id << 1 | 1, mid + 1, r, i, val);
        tree[id] = Node(min(tree[id << 1].val, tree[id << 1 | 1].val),
                        tree[id << 1].sz + tree[id << 1 | 1].sz);
    }

    int getPoint(int id, int l, int r, int i) {
        if (i < l || i > r)
            return 0;
        if (l == r)
            return tree[id].val;
        int mid = (l + r) >> 1;
        if (i <= mid)
            return getPoint(id << 1, l, mid, i);
        return getPoint(id << 1 | 1, mid + 1, r, i);
    }

    int getNumGreaterX(int id, int l, int r, int x) {
        if (tree[id].val > x)
            return tree[id].sz;
        if (l == r)
            return 0;
        int mid = (l + r) >> 1;
        return getNumGreaterX(id << 1, l, mid, x) +
               getNumGreaterX(id << 1 | 1, mid + 1, r, x);
    }

    void update(int i, int val) { update(1, 1, n, i, val); }
    int getPoint(int i) { return getPoint(1, 1, n, i); }
    int getNumGreaterX(int x) { return getNumGreaterX(1, 1, n, x); }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    fu(i, 1, m) cin >> a[i];

    vector<int> res(n + 1, 0);
    fu(l, 1, m) {
        SegmentTree point(n + 1);
        fu(r, l, min(l + k - 1, m)) {
            res[a[r]] =
                max(res[a[r]], point.getNumGreaterX(point.getPoint(a[r])) + 1);
            point.update(a[r], 1);
        }

        fu(i, 1, n) {
            res[i] = max(res[i], point.getNumGreaterX(point.getPoint(i)) + 1);
        }
    }
    fu(i, 1, n) cout << res[i] << ' ';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}