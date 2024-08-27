
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

    int getSize(int u) {
        return sz[findRoot(u)];
    }
};
void solve() {
    int nRow, nCol;
    cin >> nRow >> nCol;
    vector<vector<char>> a(nRow + 1, vector<char>(nCol + 1));
    fu(i, 1, nRow) {
        fu(j, 1, nCol) {
            cin >> a[i][j];
        }
    }

    Dsu dsu(nRow * nCol);

    auto convert = [&](int i, int j) {
        return (i - 1) * nCol + j;
    };

    auto inBoard = [&](int i, int j) {
        return 1 <= i && i <= nRow && 1 <= j && j <= nCol;
    };

    fu(i, 1, nRow) {
        fu(j, 1, nCol) {
            if (a[i][j] == '.') continue;
            pii left_coor = {i, j - 1};
            pii up_coor = {i - 1, j};

            if (inBoard(left_coor.ff, left_coor.ss) && a[left_coor.ff][left_coor.ss] == '#') {
                dsu.join(convert(i, j), convert(left_coor.ff, left_coor.ss));
            }

            if (inBoard(up_coor.ff, up_coor.ss) && a[up_coor.ff][up_coor.ss] == '#') {
                dsu.join(convert(i, j), convert(up_coor.ff, up_coor.ss));
            }
        }
    }

    int res = 0;
    fu(i, 1, nRow) {
        int sum = 0, cnt = 0;
        set<int> roots;
        fu(j, 1, nCol) {
            if (a[i][j] == '#') {
                roots.insert(dsu.findRoot(convert(i, j)));
                continue;
            }
            cnt++;
            pii up_coor = {i - 1, j};
            pii down_coor = {i + 1, j};

            if (inBoard(up_coor.ff, up_coor.ss) && a[up_coor.ff][up_coor.ss] == '#') {
                roots.insert(dsu.findRoot(convert(up_coor.ff, up_coor.ss)));
            }

            if (inBoard(down_coor.ff, down_coor.ss) && a[down_coor.ff][down_coor.ss] == '#') {
                roots.insert(dsu.findRoot(convert(down_coor.ff, down_coor.ss)));
            }
        }
        for (int root : roots) {
            sum += dsu.getSize(root);
        }
        res = max(res, sum + cnt);
    }

    fu(j, 1, nCol) {
        int sum = 0;
        set<int> roots;
        int cnt = 0;
        fu(i, 1, nRow) {
            if (a[i][j] == '#') {
                roots.insert(dsu.findRoot(convert(i, j)));
                continue;
            }
            cnt++;
            pii left_coor = {i, j - 1};
            pii right_coor = {i, j + 1};

            if (inBoard(left_coor.ff, left_coor.ss) && a[left_coor.ff][left_coor.ss] == '#') {
                roots.insert(dsu.findRoot(convert(left_coor.ff, left_coor.ss)));
            }

            if (inBoard(right_coor.ff, right_coor.ss) && a[right_coor.ff][right_coor.ss] == '#') {
                roots.insert(dsu.findRoot(convert(right_coor.ff, right_coor.ss)));
            }
        }
        for (int root : roots) {
            sum += dsu.getSize(root);
        }
        res = max(res, sum + cnt);
    }

    cout << res << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}