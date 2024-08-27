
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Node {
    int param;
    vector<int> p;
    vector<int> edge;
    Node() {
        param = 0;
        p.clear();
        edge.clear();
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pii> p(n + 1);
    fu(i, 1, n) cin >> p[i].ff >> p[i].ss;
    vector<Node> a;

    fu(i, 1, n) {
        fu(j, 1, n) {
            fu(k, 1, n) {
                if (i == j || j == k || i == k)
                    continue;
                Node node = Node();

                node.p.push_back(i);
                node.p.push_back(j);
                node.p.push_back(k);

                int x = (p[i].ff - p[j].ff) * (p[i].ff - p[j].ff) +
                        (p[i].ss - p[j].ss) * (p[i].ss - p[j].ss);
                int z = (p[i].ff - p[k].ff) * (p[i].ff - p[k].ff) +
                        (p[i].ss - p[k].ss) * (p[i].ss - p[k].ss);
                int y = (p[j].ff - p[k].ff) * (p[j].ff - p[k].ff) +
                        (p[j].ss - p[k].ss) * (p[j].ss - p[k].ss);

                node.edge.push_back(x);
                node.edge.push_back(y);
                node.edge.push_back(z);

                node.param = node.edge[0] + node.edge[1] + node.edge[2];
                a.push_back(node);
            }
        }
    }

    auto distinctPoint = [](Node x, Node y) {
        fu(i, 0, 2) {
            fu(j, 0, 2) {
                if (x.p[i] == y.p[j])
                    return false;
            }
        }
        return true;
    };

    auto equalEdge = [](Node x, Node y) {
        fu(i, 0, 2) {
            if (x.edge[i] != y.edge[i])
                return false;
        }
        return true;
    };

    sort(a.begin(), a.end(), [](Node x, Node y) { return x.param < y.param; });

    int res = 0;
    for (int l = 0, r = 0; r < a.size(); r++) {
        while (r + 1 < a.size() && a[r + 1].param == a[l].param)
            r++;
        if (r - l + 1 <= 1) {
            l = r + 1;
            continue;
        }
        // cout << l << " " << r << "\n";
        for (int i = l; i <= r; i++) {
            if (a[i].p[0] >= a[i].p[1] || a[i].p[1] >= a[i].p[2])
                continue;
            for (int j = l; j <= r; j++) {
                if (i == j) {
                    continue;
                }
                if (a[i].param == a[j].param) {
                    // fu(cc, 0, 2) { cout << a[i].p[cc] << " "; }
                    // cout << "\n";
                    // fu(cc, 0, 2) { cout << a[i].edge[cc] << " "; }
                    // cout << "\n\n";

                    // fu(cc, 0, 2) { cout << a[j].p[cc] << " "; }
                    // cout << "\n";
                    // fu(cc, 0, 2) { cout << a[j].edge[cc] << " "; }
                    // cout << "\n\n";
                    // cout << "------------------------------\n";
                    if (distinctPoint(a[i], a[j]) && equalEdge(a[i], a[j])) {
                        res++;

                        // fu(cc, 0, 2) { cout << a[i].p[cc] << " "; }
                        // cout << "\n";
                        // fu(cc, 0, 2) { cout << a[i].edge[cc] << " "; }
                        // cout << "\n\n";

                        // fu(cc, 0, 2) { cout << a[j].p[cc] << " "; }
                        // cout << "\n";
                        // fu(cc, 0, 2) { cout << a[j].edge[cc] << " "; }
                        // cout << "\n\n";
                        // cout << "------------------------------\n";
                    }
                }
            }
        }
        l = r + 1;
    }
    cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}