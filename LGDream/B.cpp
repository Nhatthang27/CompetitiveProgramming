
#include <bits/stdc++.h>
#define int long long
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
    int nr, nc, n, sr, sc;
    cin >> nr >> nc >> n >> sr >> sc;
    vector<pii> des(n + 1);
    fu(i, 1, n) {
        int x, y;
        cin >> x >> y;
        des[i] = {x, y};
    }

    vector<vector<bool>> board(nr + 1, vector<bool>(nc + 1, false));
    vector<pii> walls;
    fu(i, 1, nr) {
        string s;
        cin >> s;
        fu(j, 1, nc) {
            if (s[j - 1] == 'W') {
                board[i][j] = true;
                walls.push_back({i, j});
            }
        }
    }

    vector<vector<int>> d_src(nr + 1, vector<int>(nc + 1, 1e18));
    d_src[sr][sc] = 0;
    queue<pii> q;
    q.push({sr, sc});
    while (!q.empty()) {
        auto [cur_r, cur_c] = q.front();
        q.pop();
        fu(i, 0, 3) {
            int new_r = cur_r + dx[i];
            int new_c = cur_c + dy[i];
            if (new_r >= 1 && new_r <= nr && new_c >= 1 && new_c <= nc && board[new_r][new_c] == false && d_src[new_r][new_c] == 1e18) {
                d_src[new_r][new_c] = d_src[cur_r][cur_c] + 1;
                q.push({new_r, new_c});
            }
        }
    }

    int res = 0;
    fu(i, 1, n) {
        res += d_src[des[i].first][des[i].second];
    }

    for (auto [r, c] : walls) {
        fu(i, 0, 3) {
            int new_r = r + dx[i];
            int new_c = c + dy[i];
            if (new_r >= 1 && new_r <= nr && new_c >= 1 && new_c <= nc && board[new_r][new_c] == false) {
                d_src[r][c] = min(d_src[r][c], d_src[new_r][new_c] + 1);
            }
        }
    }

    vector<vector<vector<int>>> d_des(n + 1, vector<vector<int>>(nr + 1, vector<int>(nc + 1, 1e18)));
    fu(i, 1, n) {
        auto [r, c] = des[i];
        d_des[i][r][c] = 0;
        q.push({r, c});
        while (!q.empty()) {
            auto [cur_r, cur_c] = q.front();
            q.pop();
            fu(j, 0, 3) {
                int new_r = cur_r + dx[j];
                int new_c = cur_c + dy[j];
                if (new_r >= 1 && new_r <= nr && new_c >= 1 && new_c <= nc && board[new_r][new_c] == false && d_des[i][new_r][new_c] == 1e18) {
                    d_des[i][new_r][new_c] = d_des[i][cur_r][cur_c] + 1;
                    q.push({new_r, new_c});
                }
            }
        }
    }

    for (auto [r, c] : walls) {
        fu(i, 1, n) {
            fu(j, 0, 3) {
                int new_r = r + dx[j];
                int new_c = c + dy[j];
                if (new_r >= 1 && new_r <= nr && new_c >= 1 && new_c <= nc && board[new_r][new_c] == false) {
                    d_des[i][r][c] = min(d_des[i][r][c], d_des[i][new_r][new_c] + 1);
                }
            }
        }
    }

    int net = 0;

    for (auto [r, c] : walls) {
        int tmp = 0;
        fu(i, 1, n) {
            tmp += min(d_des[i][sr][sc], d_des[i][r][c] + d_src[r][c]);
        }
        if (res - tmp > 0) net += (res - tmp);
    }
    cout << res << ' ' << net << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}