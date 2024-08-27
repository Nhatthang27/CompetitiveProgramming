
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) {
        x = _x, y = _y;
    }
    bool operator<(const Point& other) {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

struct cmp {
    bool operator()(const Point& a, const Point& b) const {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    fu(i, 1, n) cin >> x[i], x[i] += x[i - 1];
    fu(i, 1, n) cin >> y[i], y[i] += y[i - 1];
    x[0] = y[0] = 0;
    int h = LONG_LONG_MAX;

    auto getDist = [&](int i, int j) {
        if (abs(x[j] - x[i]) > 1e9 || abs(y[j] - y[i]) > 1e9) return LONG_LONG_MAX;
        return (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
    };
    fu(i, 0, n) {
        fu(j, i + 1, n) {
            h = min(h, getDist(i, j));
        }
    }
    cout << h << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t-- > 0) {
        solve();
    }
}