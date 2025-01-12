#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> type; // -1  -- default, 0 -- root, 1 -- leaf, 2 -- bud

void dfs(int v, int p)
{
    bool leaves = false;
    for (auto to : g[v])
    {
        if (to == p)
            continue;
        dfs(to, v);
        if (type[to] == 1)
            leaves = true;
    }
    if (v != p)
    {
        if (!leaves)
            type[v] = 1;
        else
            type[v] = 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n;
        cin >> n;
        g.assign(n, vector<int>());
        type.assign(n, -1);
        for (int i = 0; i < n - 1; ++i)
        {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        type[0] = 0;
        dfs(0, 0);
        bool root_leaf = false;
        for (auto v : g[0])
        {
            if (type[v] == 1)
            {
                root_leaf = true;
            }
        }
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            k += (type[i] == 2);
        }
        cout << n - 2 * k - root_leaf << '\n';
    }
    return 0;
}