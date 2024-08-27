
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
    int id;
    Point(int _x = 0, int _y = 0, int _id = 0) {
        x = _x, y = _y, id = _id;
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
    vector<Point> points;
    fu(i, 0, n - 1) {
        int x, y, id;
        cin >> x >> y;
        points.push_back(Point(x, y, i));
    }

    auto dist = [&](Point a, Point b) {
        if (abs(a.x - b.x) > 1e9 || abs(a.y - b.y) > 1e9) return LONG_LONG_MAX;
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    };

    int p1 = 0, p2 = 1;
    int res = dist(points[0], points[1]);
    sort(points.begin(), points.end());
    set<Point, cmp> s;

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
                p1 = p.id;
                p2 = cur.id;
            }
        }
        s.insert(p);
    }
    if (p1 > p2) swap(p1, p2);
    cout << p1 << ' ' << p2 << ' ';
    cout << fixed << setprecision(6) << sqrt(res) << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t-- > 0) {
        solve();
    }
}