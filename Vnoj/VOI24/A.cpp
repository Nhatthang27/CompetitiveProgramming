
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

struct Elec {
    int x, y, w;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<Elec> e(m + 1);
    fu(i, 1, m) {
        cin >> e[i].x >> e[i].y >> e[i].w;
    }

    // int max_row = 0;
    // int max_col = 0;
    int max_row = n;
    int max_col = n;
    auto compress = [&]() {
        vector<int> vx, vy;
        fu(i, 1, m) {
            vx.push_back(e[i].x);
            vy.push_back(e[i].y);
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
        vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
        fu(i, 1, m) {
            e[i].x = lower_bound(vx.begin(), vx.end(), e[i].x) - vx.begin() + 1;
            e[i].y = lower_bound(vy.begin(), vy.end(), e[i].y) - vy.begin() + 1;
            max_row = max(max_row, e[i].x);
            max_col = max(max_col, e[i].y);
        }
    };
    // compress();
    vector<int> s_row(max_row + 1, 0), s_col(max_col + 1, 0);
    fu(i, 1, m) {
        s_row[e[i].x] += e[i].w;
        s_col[e[i].y] += e[i].w;
    }
    vector<int> top_row, top_col;
    auto findTop = [&]() {
        vector<pair<int, int>> value_row, value_col;
        fu(i, 1, max_row) {
            value_row.push_back({s_row[i], i});
        }
        fu(i, 1, max_col) {
            value_col.push_back({s_col[i], i});
        }
        sort(value_row.begin(), value_row.end(), greater<pair<int, int>>());
        sort(value_col.begin(), value_col.end(), greater<pair<int, int>>());
        fu(i, 0, 2) {
            top_row.push_back(value_row[i].second);
            top_col.push_back(value_col[i].second);
        }
    };
    findTop();
    while(q --> 0) {
        int id, add;
        cin >> id >> add;
        s_row[e[id].x] += add;
        s_col[e[id].y] += add;
        int res = max(s_row[top_row[0]] + s_row[top_row[1]] + s_row[top_row[2]], s_col[top_col[0]] + s_col[top_col[1]], s_col[top_col[2]]);
        if (e[id].x == top_row[0] || e[id].x == top_row[1] || e[id].x == top_row[2]) {
            res = max(res, s_row[top_row[0]] + s_row[top_row[1]] + s_row[top_row[2]] + add);
        } else {
            res = max(res, s_row[top_row[0]] + s_row[top_row[1]] + s_row[e[id].x] + add);
        }

        if (e[id].y == top_col[0] || e[id].y == top_col[1] || e[id].y == top_col[2]) {
            res = max(res, s_col[top_col[0]] + s_col[top_col[1]] + s_col[top_col[2]] + add);
        } else {
            res = max(res, s_col[top_col[0]] + s_col[top_col[1]] + s_col[e[id].y] + add);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}