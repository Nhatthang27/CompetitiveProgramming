
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
        TreeNode *root = new TreeNode(val);
        return root;
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    TreeNode *root = new TreeNode(a[1]);
    fu(i, 2, n) {
        insertIntoBST(root, a[i]);
    }

    unordered_map<int, int> depth;
    unordered_map<int, int> par;

    function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int d) {
        if (!node) return;
        depth[node->val] = d;
        if (node->left) {
            par[node->left->val] = node->val;
            dfs(node->left, d + 1);
        }
        if (node->right) {
            par[node->right->val] = node->val;
            dfs(node->right, d + 1);
        }
    };

    dfs(root, 0);
    // // print node with depth and its parent
    int x, y;
    cin >> x >> y;
    int mi = min(x, y);
    int ma = max(x, y);
    if (depth[x] > depth[y]) swap(x, y);
    while (depth[x] < depth[y]) {
        // cout << x << " " << y << "\n";
        mi = min(mi, y);
        ma = max(ma, y);
        y = par[y];
    }
    while (x != y) {
        // cout << x << " " << y << "\n";
        mi = min({mi, x, y});
        ma = max({ma, x, y});
        x = par[x];
        y = par[y];
    }
    mi = min({mi, x, y});
    ma = max({ma, x, y});
    cout << mi << " " << ma << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}