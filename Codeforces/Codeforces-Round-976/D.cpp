
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

struct Dsu
{
    vector<int> root, sz;

    Dsu(int n)
    {
        root.assign(n + 1, -1);
        sz.assign(n + 1, 1);
        for (int u = 1; u <= n; u++)
        {
            root[u] = u;
        }
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
            if (sz[u] < sz[v])
                swap(u, v);
            root[v] = u;
            sz[u] += sz[v];
            return true;
        }
        else
        {
            return false;
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> linhkhum(n + 1, vector<int>(11, 0));

    while (m-- > 0)
    {
        int a, k, d;
        cin >> a >> d >> k;
        if (k == 0)
        {
            continue;
        }
        int start = a;
        int end = a + k * d;
        linhkhum[start][d]++;
        if (end <= n)
            linhkhum[end][d]--;
    }

    Dsu dsu(n);
    int res = n;

    fu(i, 1, n)
    {
        fu(j, 1, 10)
        {
            linhkhum[i][j] += linhkhum[max(i - j, 0LL)][j];
            if (linhkhum[i][j] > 0 && i + j <= n)
            {
                res -= dsu.join(i, i + j);
            }
        }
    }

    cout << res << endl;
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