
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int short
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    pii start, finish;
    vector<vector<char>> board(n + 1, vector<char>(m + 1));
    fu(i, 1, n) {
        fu(j, 1, m) {
            cin >> board[i][j];
            if (board[i][j] == 'S') start = {i, j};
            if (board[i][j] == 'T') finish = {i, j};
        }
    }
    vector<vector<int>> e(n + 1, vector<int>(m + 1, 0));
    int numE;
    cin >> numE;
    fu(i, 1, numE) {
        int x, y, ene;
        cin >> x >> y >> ene;
        e[x][y] = ene;
    }
    vector<vector<int>> res(n + 1, vector<int>(m + 1, -1));
    if (start == finish) {
        cout << "YES\n";
        return;
    }
    if (e[start.ff][start.ss] > 0) {
        priority_queue<pair<int, pii>> q;
        res[start.ff][start.ss] = e[start.ff][start.ss];
        q.push({e[start.ff][start.ss], start});
        while (!q.empty()) {
            auto [ene, u] = q.top();
            q.pop();
            fu(i, 0, 3) {
                int x = u.ff + dx[i];
                int y = u.ss + dy[i];
                if (x < 1 || x > n || y < 1 || y > m || board[x][y] == '#') continue;
                int newEne = max(ene - 1, e[x][y]);
                // e[x][y] = 0;
                if (res[x][y] < newEne) {
                    res[x][y] = newEne;
                    if (newEne > 0)
                        q.push({res[x][y], {x, y}});
                }
            }
        }
    }
    if (res[finish.ff][finish.ss] == -1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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