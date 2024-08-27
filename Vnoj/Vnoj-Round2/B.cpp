
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
    int n;
    cin >> n;
    vector<int> pos(n + 2), color(n + 2), bi(n + 2);
    vector<pii> res;
    fu(i, 1, n) {
        int c;
        cin >> c;
        pos[i] = c;    // vi tri i co mau c
        color[c] = i;  // mau c dang o vi tri i
    }

    fu(c, 1, n) {
        if (color[c] == c) continue;
        res.push_back({color[c], n + 1});

        for (int p = color[c] - 1; p >= c; p--) {
            res.push_back({p, p + 1});
            int cur_color = pos[p];

            color[cur_color] = p + 1;
            pos[p + 1] = cur_color;
        }
        res.push_back({n + 1, c});
        color[c] = c;
        pos[c] = c;
    }
    cout << res.size() << "\n";
    for (auto [x, y] : res) {
        cout << x << " " << y << "\n";
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