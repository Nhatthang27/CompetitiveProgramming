
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> cnt_l(n + 1, 0);
    vector<int> cnt_r(m + 1, 0);

    vector<vector<int>> adj(n + 1);

    fu(i, 1, q) {
        int u, v;
        cin >> u >> v;
        cnt_l[u]++;
        cnt_r[v]++;

        adj[u].push_back(v);
    }

    vector<pii> edges;
    fu(u, 1, n) {
        if (cnt_l[u] == 0) continue;
        for (auto v : adj[u]) {
            edges.push_back({cnt_l[u], cnt_r[v]});
        }
    }

    int total = 0;

    sort(cnt_l.begin() + 1, cnt_l.end(), greater<int>());
    // vector<int> vl(n + 1);
    unordered_map<int, int> vl;
    int max_value = n;
    fu(i, 1, n) {
        total += cnt_l[i] * max_value;
        vl[cnt_l[i]] = max_value--;
    }

    sort(cnt_r.begin() + 1, cnt_r.end(), greater<int>());
    // vector<int> vr(m + 1);
    unordered_map<int, int> vr;
    max_value = m;
    fu(i, 1, m) {
        total += cnt_r[i] * max_value;
        vr[cnt_r[i]] = max_value--;
    }

    int mi = LONG_LONG_MAX;

    for (auto [l, r] : edges) {
        mi = min(mi, (vl[l] + vr[r]));
    }
    cout << total << " " << total - mi << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}