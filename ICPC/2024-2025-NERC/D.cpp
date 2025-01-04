
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

map<string, int> TYPES = {{"set true", 1}, {"set false", 2}, {"unset true", 3}, {"unset false", 4}};
void solve()
{
    int n;
    cin >> n;
    vector<int> typeOfNode(n + 1);
    vector<vector<int>> types(5, vector<int>());
    map<pair<int, int>, bool> isExist;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string inp;
        getline(cin, inp);
        typeOfNode[i] = TYPES[inp];
        types[TYPES[inp]].push_back(i);
    }

    vector<vector<int>> adj(n + 1, vector<int>());
    if (types[1].size() == 2 || types[3].size() == 2)
    {
        cout << -1;
        return;
    }

    int r1 = types[1].empty() ? -1 : types[1][0];
    int r3 = types[3].empty() ? -1 : types[3][0];
    // cerr << r1 << " " << r3 << "\n";
    if (r1 != -1)
    {
        for (int v : types[2])
        {
            if (!isExist[{r1, v}])
            {
                adj[r1].push_back(v);
                isExist[{r1, v}] = 1;
            }
        }
    }
    if (r3 != -1)
    {
        for (int u : types[2])
        {
            if (!isExist[{u, r3}])
            {
                adj[u].push_back(r3);
                isExist[{u, r3}] = 1;
            }
        }
    }
    if (r1 != -1 && r3 != -1 && !isExist[{r1, r3}])
    {
        adj[r1].push_back(r3);
        isExist[{r1, r3}] = 1;
    }

    int root = (r1 != -1 ? r1 : r3);

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        int tu = typeOfNode[u];
        int tv = typeOfNode[v];

        if (tu == 4 && tv == 4)
        {
            if (!isExist[{u, v}])
            {
                adj[u].push_back(v);
                isExist[{u, v}] = 1;
            }
        }
        else if (tu == 4)
        {
            if (r1 == -1)
            {
                cout << -1;
                return;
            }
            if (!isExist[{u, r1}])
            {
                adj[u].push_back(r1);
                isExist[{u, r1}] = 1;
            }
        }
        else if (tv == 4)
        {
            if (r3 == -1)
            {
                cout << -1;
                return;
            }
            if (!isExist[{r3, v}])
            {
                adj[r3].push_back(v);
                isExist[{r3, v}] = 1;
            }
        }
        if (!isExist[{u, v}])
            adj[u].push_back(v);
    }

    // for (int u = 1; u <= n; u++)
    //     for (int v : adj[u])
    //     {
    //         cerr << u << " " << v << "\n";
    //     }

    vector<int> vst(n + 1, 0), ans;
    stack<int> topo;

    function<void(int)> dfs = [&](int u)
    {
        vst[u] = 1;
        for (auto v : adj[u])
        {
            if (vst[v] == 1)
            {
                cout << -1;
                exit(0);
            }
            if (!vst[v])
                dfs(v);
        }
        topo.push(u);
        vst[u] = 2;
    };

    // cerr << root << "\n";
    if (root != -1)
        dfs(root);

    for (int u : types[4])
    {
        if (!vst[u])
        {
            dfs(u);
        }
    }

    while (!topo.empty())
    {
        ans.push_back(topo.top());
        topo.pop();
    }

    if (ans.size() != n)
    {
        cout << -1;
        return;
    }
    for (int u : ans)
    {
        cout << u << " ";
    }
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