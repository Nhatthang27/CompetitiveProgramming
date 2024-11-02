
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
using namespace std;
struct DSU
{
    vector<int> p, sz;
    int n;
    DSU(int _n) : n(_n)
    {
        p.resize(n);
        iota(all(p), 0);
        sz.assign(n, 1);
    }
    int find(int x)
    {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        return true;
    }
    int size(int x)
    {
        return sz[find(x)];
    }
    int components()
    {
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            if (p[i] == i)
                ++res;
        }
        return res;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);

    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i);

    for (int i = 0; i < m; ++i)
    {
        int a, d, k;
        cin >> a >> d >> k;
        for (int j = a + d, step = 1; step <= k; ++step)
        {
            if (j > n)
                break;
            dsu.unite(j, j - d);
            if (s.find(j) == s.end())
            {
                auto it = s.lower_bound(j);
                if (it == s.end())
                {
                    if (j + d <= n && step + 1 <= k)
                    {
                        dsu.unite(j, j + d);
                    }
                    break;
                }
                int x = (int)ceil((*it - j) * 1.0 / d);
                step += x - 1;
                if (step >= k)
                    break;
                j += x * d;
                dsu.unite(j, j - x * d - d);
                dsu.unite(j, j - x * d);
            }
            else
            {
                s.erase(j);
                j += d;
            }
        }
    }

    cout << dsu.components() << '\n';
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