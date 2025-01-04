#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

const int N = 2e3 + 5;
const ll INF = 2e18;

struct Query
{
    int l, r;
    ll k;
    bool operator<(const Query &q)
    {
        return k < q.k;
    }
};

class Fenwick2D
{
private:
    int n;
    vector<vector<int>> ft;

public:
    Fenwick2D(int _n) : n(_n)
    {
        ft.resize(n + 1);
        for (int i = 0; i <= n; i++)
            ft[i].assign(n + 1, 0);
    }

    void reset()
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                ft[i][j] = 0;
            }
        }
    }

    void update(int r, int c, int val)
    {
        for (int i = r; i <= n; i += i & -i)
        {
            for (int j = c; j <= n; j += j & -j)
            {
                ft[i][j] += val;
            }
        }
    }

    int query(int r, int c)
    {
        int ret = 0;
        for (int i = r; i > 0; i -= i & -i)
        {
            for (int j = c; j > 0; j -= j & -j)
            {
                ret += ft[i][j];
            }
        }
        return ret;
    }

    int query(int r1, int c1, int r2, int c2)
    {
        return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int q;
    cin >> q;
    vector<Query> que(q);
    for (auto &[l, r, k] : que)
        cin >> l >> r >> k;

    // Precompute f
    vector f(n, vector<ll>(n, 0));
    // vector<vector<ll>> f(n, vector<ll>(n, 0));
    {
        for (int i = 0; i < n; i++)
        {
            ll cur = 0;
            for (int j = i; j >= 0; j--)
            {
                cur += abs(a[j] - a[i]);
                if (i > 0)
                    f[j][i - 1] = (j < i ? f[j][i - 1] : 0) + cur;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            f[i][j] = INF;
        }
    }
    // }

    // Make orders
    vector<pair<int, int>> orderf;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            orderf.emplace_back(i, j);
        }
    }

    sort(all(orderf), [&f](auto x, auto y)
         { return f[x.first][x.second] < f[y.first][y.second]; });

    vector<int> orderq(q);
    iota(all(orderq), 0);
    sort(all(orderq), [&que](int i, int j)
         { return que[i] < que[j]; });

    // Answer queries
    vector<ll> ans(q);
    Fenwick2D ft(n);
    int j = 0;
    for (int i : orderq)
    {
        Query qq = que[i];
        while (j < (int)orderf.size() && f[orderf[j].first][orderf[j].second] <= qq.k)
        {
            ft.update(orderf[j].first + 1, orderf[j].second + 1, 1);
            j++;
        }
        ans[i] = ft.query(qq.l, qq.l, qq.r, qq.r);
    }

    for (auto i : ans)
        cout << i << '\n';

    return 0;
}
