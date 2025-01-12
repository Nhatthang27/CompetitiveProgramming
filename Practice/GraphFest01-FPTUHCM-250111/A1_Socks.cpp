
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Dsu
{
    vector<int> root, sz;

    Dsu(int n)
    {
        root.assign(n, -1);
        sz.assign(n, 1);
        for (int u = 0; u < n; u++)
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> color(n);
    for (int &c : color)
    {
        cin >> c;
    }

    Dsu dsu(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.join(u, v);
    }
    vector<vector<int>> comp(n);
    for (int u = 0; u < n; u++)
    {
        comp[dsu.findRoot(u)].push_back(color[u]);
    }
    int ans = 0;
    for (int u = 0; u < n; u++)
    {
        if (comp[u].empty())
            continue;
        sort(comp[u].begin(), comp[u].end());
        int max_freq = 1;
        int freq = 1;
        for (int i = 1; i < comp[u].size(); i++)
        {
            if (comp[u][i] == comp[u][i - 1])
            {
                freq++;
            }
            else
            {
                max_freq = max(max_freq, freq);
                freq = 1;
            }
        }
        max_freq = max(max_freq, freq);
        ans += comp[u].size() - max_freq;
    }
    cout << ans << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}