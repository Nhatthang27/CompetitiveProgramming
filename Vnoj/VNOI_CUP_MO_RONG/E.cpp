
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pii> p(n);
    fu(i, 0, n - 1)
    {
        cin >> p[i].ff >> p[i].ss;
    }

    // get area of convex hull with a set of points
    auto getConvexHull = [&](vector<pii> &points)
    {
        sort(points.begin(), points.end());
        vector<pii> hull;
        for (pii p : points)
        {
            while (hull.size() >= 2 && (hull[hull.size() - 1].ff - hull[hull.size() - 2].ff) * (p.ss - hull[hull.size() - 2].ss) - (hull[hull.size() - 1].ss - hull[hull.size() - 2].ss) * (p.ff - hull[hull.size() - 2].ff) <= 0)
            {
                hull.pop_back();
            }
            hull.push_back(p);
        }
        int s = hull.size();
        for (int i = points.size() - 2; i >= 0; i--)
        {
            while (hull.size() - s >= 1 && (hull[hull.size() - 1].ff - hull[hull.size() - 2].ff) * (points[i].ss - hull[hull.size() - 2].ss) - (hull[hull.size() - 1].ss - hull[hull.size() - 2].ss) * (points[i].ff - hull[hull.size() - 2].ff) <= 0)
            {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        hull.pop_back();
        return hull;
    };

    // get area of set of point
    auto getArea = [&](vector<pii> &points)
    {
        int res = 0;
        for (int i = 0; i < points.size(); i++)
        {
            res += points[i].ff * points[(i + 1) % points.size()].ss - points[i].ss * points[(i + 1) % points.size()].ff;
        }
        return res;
    };

    // get all subset at least 3 points of p
    int res = 0;
    for (int mask = 1; mask < (1 << p.size()); mask++)
    {
        vector<pii> subset;
        for (int i = 0; i < p.size(); i++)
        {
            if (mask & (1 << i))
            {
                subset.push_back(p[i]);
            }
        }
        if (subset.size() >= 3)
        {
            // for (int i = 0; i < subset.size(); i++)
            // {
            //     cout << subset[i].ff << " " << subset[i].ss << "\n";
            // }
            // cout << "\n";
            vector<pii> hull = getConvexHull(subset);
            if (hull.size() >= 3)
            {
                int area = getArea(hull);
                if (area > 0)
                {
                    res = (res + area) % 1000000007;
                }
            }
        }
    }
    cout << res << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}