
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

const int R = 100;

struct Dsu
{
    vector<int> root, sz;
    int target;

    Dsu(int n, int target)
    {
        root.assign(n + 1, -1);
        sz.assign(n + 1, 1);
        for (int u = 1; u <= n; u++)
        {
            root[u] = u;
        }
        this->target = target;
    }

    int findRoot(int u)
    {
        return root[u] = (root[u] == u ? u : findRoot(root[u]));
    }

    bool join(int u, int v)
    {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v)
        {
            if (u == target)
            {
                root[v] = u;
                return true;
            }
            if (v == target)
            {
                root[u] = v;
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    bool check(int u, int v)
    {
        return findRoot(u) == findRoot(v);
    }
};

void solve()
{
    int l, w, n;
    cin >> l >> w >> n;
    // rectangel with width w and length l
    // n cirles with radius R and center (x,y)
    vector<pii> a(n + 1);
    fu(i, 1, n)
    {
        cin >> a[i].ff >> a[i].ss;
    }

    Dsu dsu_n1(n + 2, n + 1);
    Dsu dsu_n2(n + 2, n + 2);
    // line 0 is n + 1
    // line l is n + 2
    fu(i, 1, n)
    {
        if (a[i].ss <= R)
        {
            dsu_n1.join(i, n + 1);
            dsu_n2.join(i, n + 1);
        }
        if (a[i].ss + R >= l && a[i].ss <= l)
        {
            dsu_n2.join(i, n + 2);
            dsu_n1.join(i, n + 2);
        }
    }

    int cnt_n1 = 0, cnt_n2 = 0;
    fu(i, 1, n)
    {
        fu(j, i + 1, n)
        {
            if ((a[i].ff - a[j].ff) * (a[i].ff - a[j].ff) + (a[i].ss - a[j].ss) * (a[i].ss - a[j].ss) <= 4 * R * R)
            {
                // cout << i << " " << j << endl;
                dsu_n1.join(i, j);
                dsu_n2.join(i, j);
            }
        }
    }

    fu(i, 1, n)
    {
        if (a[i].ss <= R && dsu_n2.findRoot(i) == n + 2)
        {
            cnt_n1++;
        }
        if (a[i].ss + R >= l && a[i].ss <= l && dsu_n1.findRoot(i) == n + 1)
        {
            // cout << a[i].ff << " " << a[i].ss << endl;
            cnt_n2++;
        }
    }
    cout << min(cnt_n1, cnt_n2) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}