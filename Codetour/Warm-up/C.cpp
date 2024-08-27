
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 100;
void solve() {
    int nBan;
    cin >> nBan;
    vector<vector<bool>> bans(MAX + 1, vector<bool>(MAX + 1, false));
    fu(i, 1, nBan) {
        int x, y;
        cin >> x >> y;
        bans[x][y] = true;
    }

    int nBub;
    cin >> nBub;
    vector<pii> bubs(nBub + 1);
    fu(i, 1, nBub) {
        cin >> bubs[i].ff >> bubs[i].ss;
    }

    if (nBan == 0 && nBub == 2) {
        int dis = abs(bubs[1].ff - bubs[2].ff) + abs(bubs[1].ss - bubs[2].ss);
        cout << dis;
        return;
    }

    vector<vector<int>> res(MAX + 1, vector<int>(MAX + 1, 0));
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    fu(i, 1, nBub) {
        vector<vector<int>> dis(MAX + 1, vector<int>(MAX + 1, LONG_LONG_MAX));
        dis[bubs[i].ff][bubs[i].ss] = 0;
        queue<pii> q;
        q.push(bubs[i]);

        while (!q.empty()) {
            pii u = q.front();
            q.pop();
            fu(k, 0, 3) {
                int x = u.ff + dx[k];
                int y = u.ss + dy[k];
                if (x >= 1 && x <= MAX && y >= 1 && y <= MAX && bans[x][y] == false && dis[x][y] == LONG_LONG_MAX) {
                    dis[x][y] = dis[u.ff][u.ss] + 1;
                    q.push({x, y});
                }
            }
        }

        fu(x, 1, MAX) {
            fu(y, 1, MAX) {
                if (dis[x][y] != LONG_LONG_MAX) {
                    res[x][y] += dis[x][y];
                } else {
                    res[x][y] = LONG_LONG_MAX;
                }
            }
        }
    }
    int minDis = LONG_LONG_MAX;
    fu(x, 1, MAX) {
        fu(y, 1, MAX) {
            if (res[x][y] != LONG_LONG_MAX) {
                minDis = min(minDis, res[x][y]);
            }
        }
    }
    cout << (minDis == LONG_LONG_MAX ? -1 : minDis);
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}