
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
        int mx, cnt, mx2, cnt2;
        Node(int _mx = 0, int _cnt = 0, int _mx2 = 0, int _cnt2 = 0) {
            mx = _mx;
            cnt = _cnt;
            mx2 = _mx2;
            cnt2 = _cnt2;
        }
    };

    int n;
    vector<Node> nodes;

    SegmentTree(int _n) {
        n = _n;
        nodes.assign(4 * n, Node());
    }

    void build(int id, int l, int r, vector<int> &inp) {
        if (l == r) {
            nodes[id] = Node(inp[l], 1, 0, 0);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, inp);
        build(id * 2 + 1, mid + 1, r, inp);
        nodes[id] = merge(nodes[id * 2], nodes[id * 2 + 1]);
    }

    Node merge(Node &lef, Node &rig) {
        vector<pii> vec({{lef.mx, lef.cnt},
                         {rig.mx, rig.cnt},
                         {lef.mx2, lef.cnt2},
                         {rig.mx2, rig.cnt2}});
        sort(vec.begin(), vec.end(), greater<pii>());
        Node res;
        res.mx = vec[0].ff;
        if (vec[0].ff == vec[1].ff) {
            res.cnt = vec[0].ss + vec[1].ss;
            res.mx2 = vec[2].ff;
            res.cnt2 =
                vec[2].ff == vec[3].ff ? vec[2].ss + vec[3].ss : vec[2].ss;
        } else {
            res.cnt = vec[0].ss;
            res.mx2 = vec[1].ff;
            res.cnt2 =
                vec[1].ff == vec[2].ff ? vec[1].ss + vec[2].ss : vec[1].ss;
        }
        return res;
    }

    void show(int id, int l, int r) {
        cout << id << " " << nodes[id].mx << "," << nodes[id].cnt << " "
             << nodes[id].mx2 << "," << nodes[id].cnt2 << endl;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        show(id * 2, l, mid);
        show(id * 2 + 1, mid + 1, r);
    }

    void update(int pos, int val, int id, int l, int r) {
        if (l > pos || r < pos)
            return;
        if (l == r) {
            nodes[id] = Node(val, 1, 0, 0);
            return;
        }
        int mid = (l + r) / 2;
        update(pos, val, id * 2, l, mid);
        update(pos, val, id * 2 + 1, mid + 1, r);
        nodes[id] = merge(nodes[id * 2], nodes[id * 2 + 1]);
    }

    Node getNumSecondInRange(int u, int v, int id, int l, int r) {
        if (l > v || r < u)
            return Node();
        if (l >= u && r <= v) {
            return Node(nodes[id].mx, nodes[id].cnt, nodes[id].mx2,
                        nodes[id].cnt2);
        }
        int mid = (l + r) / 2;
        Node left = getNumSecondInRange(u, v, id * 2, l, mid);
        Node right = getNumSecondInRange(u, v, id * 2 + 1, mid + 1, r);
        return merge(left, right);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    SegmentTree st(n);
    st.build(1, 1, n, a);
    // st.show(1, 1, n);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            st.update(x, y, 1, 1, n);
        } else {
            auto res = st.getNumSecondInRange(x, y, 1, 1, n);
            cout << res.cnt2 << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}