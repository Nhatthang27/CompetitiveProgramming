
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
    vector<int> p;
    vector<int> edge;
    Node() {
        p.clear();
        edge.clear();
    }

    bool operator>(const Node &other) const {
        return edge[0] + edge[1] + edge[2] >
               other.edge[0] + other.edge[1] + other.edge[2];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pii> p(n + 1);
    fu(i, 1, n) cin >> p[i].ff >> p[i].ss;
    unordered_map<vector<int>, vector<Node>> a;

    int res = 0;

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
                int y = (p[j].ff - p[k].ff) * (p[j].ff - p[k].ff) +
                        (p[j].ss - p[k].ss) * (p[j].ss - p[k].ss);
                int z = (p[i].ff - p[k].ff) * (p[i].ff - p[k].ff) +
                        (p[i].ss - p[k].ss) * (p[i].ss - p[k].ss);

                node.edge.push_back(x);
                node.edge.push_back(y);
                node.edge.push_back(z);
            }
        }
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