
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
    vector<Point> points;
    fu(i, 0, n) points.push_back(Point(x[i], y[i]));
    // fu(i, 0, n) cout << points[i].x << ' ' << points[i].y << '\n';
    sort(points.begin(), points.end());
    // fu(i, 0, n) cout << points[i].x << ' ' << points[i].y << '\n';
    set<Point, cmp> s;

    auto dist = [&](Point a, Point b) {
        if (abs(a.x - b.x) > 1e9 || abs(a.y - b.y) > 1e9) return LONG_LONG_MAX;
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    };
    int res = dist(points[0], points[1]);

    for (Point p : points) {
        int h = sqrt(res) + 1;
        Point cur = Point(LONG_LONG_MIN, p.y - h);

        while (true) {
            auto it = s.upper_bound(cur);
            if (it == s.end()) break;

            cur = *it;
            if (cur.y - p.y > h) break;

            if (p.x - cur.x > h) {
                s.erase(it);
                continue;
            }

            if (dist(p, cur) < res) {
                res = dist(p, cur);
            }
        }
        s.insert(p);
    }
    cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t-- > 0) {
        solve();
    }
}