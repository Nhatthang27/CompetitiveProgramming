
#include <bits/stdc++.h>
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Node {
    long long paths = 0;              // number of same color paths across this edge
    unordered_map<int, int> cl_repo;  // cl_repo[c] = number of color c in subtree
};

void solve() {
    int n;
    cin >> n;
    vector<vector<pii>> adj(n + 1, vector<pii>());
    vector<int> color(n + 1, 0);
    vector<int> totalColor(n + 1, 0);
    vector<long long> res(n + 1, 0);

    fu(i, 1, n) cin >> color[i], totalColor[color[i]]++;

    fu(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    // 1. Đỉnh u, cạnh edgeId là cạnh từ u lên parent của u
    // 2. Duyệt các đỉnh v là đỉnh con kề u
    // 3. Số đường đi hợp lệ qua cạnh u v (nối với các v khác + nối với u và các par của u)
    // 4. Dựa trên kết quả từ các đỉnh v ta sẽ tính kết quả cho đỉnh u
    // 5. Với từng kết quả v, ta - (số đường đi mà nối với các v khác,
    //    + số đường đi mà nối với u + các par của u)
    // 6. Lúc này thiếu các đỉnh cha của u, nên ta cộng thêm các đỉnh cùng màu u ở trên
    function<Node(int, int, int)> dfs = [&](int u, int par, int edgeId) -> Node {
        Node node_u;
        for (auto [v, id] : adj[u]) {
            if (v == par) continue;
            Node node_v = dfs(v, u, id);
            node_u.paths += node_v.paths;

            if (node_u.cl_repo.size() < node_v.cl_repo.size()) {
                swap(node_u.cl_repo, node_v.cl_repo);
            }

            for (auto [c, cnt] : node_v.cl_repo) {
                node_u.paths -= 2LL * node_u.cl_repo[c] * cnt;
                node_u.cl_repo[c] += cnt;
            }
        }

        node_u.paths -= node_u.cl_repo[color[u]];                         // 1. số đường đi nối với u
        node_u.cl_repo[color[u]]++;                                       //
        node_u.paths += totalColor[color[u]] - node_u.cl_repo[color[u]];  // 2. số màu ở trên u cần cộng thêm
        res[edgeId] = node_u.paths;
        return node_u;
    };

    for (auto [v, id] : adj[1]) {
        dfs(v, 1, id);
    }
    fu(i, 1, n - 1) cout << res[i] << " ";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}