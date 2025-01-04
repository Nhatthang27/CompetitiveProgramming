
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Dsu
{
    vector<int> root, sz;
    int n;

    Dsu(int _n)
    {
        n = _n;
        root.assign(n + 7, 0);
        sz.assign(n + 7, 1);
        for (int i = 1; i <= n; i++)
            root[u] = u;
    }

    int getRoot(int u)
    {
        return root[u] = (root[u] == u ? u : getRoot(root[u]));
    }

    int join(int u, int v)
    {
        u = getRoot(u);
        v = getRoot(v);
        if (u != v)
        {
            if (sz[u] > sz[v])
                swap(u, v);
            root[v] = u;
            sz[u] +=
        }
    }
};

void solve() {}
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