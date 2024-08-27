
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Dsu {
    vector<int> root, sz;

    Dsu(int n) {
        root.assign(n + 1, -1);
        sz.assign(n + 1, 1);
        for (int u = 1; u <= n; u++) {
            root[u] = u;
        }
    }

    int findRoot(int u) {
        return root[u] = (root[u] == u ? u : findRoot(root[u]));
    }

    int getSize(int u) {
        return sz[findRoot(u)];
    }
    bool join(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v) {
            if (sz[u] < sz[v])
                swap(u, v);
            root[v] = u;
            sz[u] += sz[v];
            return true;
        } else {
            return false;
        }
    }
};
void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<pii> edges(m + 1);
    fu(i, 1, m) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    auto makeComps = [&](int x) {
        Dsu dsu(n);
        fu(i, 1, m) {
            if (i == x) continue;
            dsu.join(edges[i].ff, edges[i].ss);
        }

        vector<bool> vst(n + 1, 0);
        vector<int> comps;
        fu(i, 1, n) {
            int comp = dsu.findRoot(i);
            if (!vst[comp]) {
                comps.push_back(dsu.getSize(i));
                vst[comp] = 1;
            }
        }
        return comps;
    };

    auto getScore = [&](vector<int> comps) {
        sort(comps.begin(), comps.end());
        int s1 = 0, sum = n;

        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int x : comps) {
            fd(i, sum, x) {
                dp[i] = dp[i] | dp[i - x];
            }
        }
        int score = LONG_LONG_MAX;
        fu(i, 1, sum) {
            if (dp[i]) {
                score = min(score, i * i + (sum - i) * (sum - i));
            }
        }
        return score;
    };

    int numComps = makeComps(0).size();
    int res = LONG_LONG_MAX;
    fu(i, 0, m) {
        vector<int> comp = makeComps(i);
        if ((i == 0 && comp.size() == 1) || (i != 0 && comp.size() <= numComps)) continue;
        int base = ((int)comp.size() - (i == 0 ? 1 : 2)) * c;
        res = min(res, getScore(comp) + base);
    }
    cout << (res == LONG_LONG_MAX ? -1 : res) << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}