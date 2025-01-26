
#include <bits/stdc++.h>
const int MAX = 3e5 + 1;
using namespace std;
int n, m, num_q;
vector<int> adj[MAX];
vector<int> d(MAX, -1), d1(MAX, -1), redis(MAX);
bool visited[MAX];

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

    bool isSameComponent(int u, int v)
    {
        return findRoot(u) == findRoot(v);
    }
};

int getDiameter(vector<int> adj[], int n, int root)
{
    int dia = 0;
    int leaf1 = -1;
    int max_d = -1;
    function<void(int, vector<int> &)> bfs = [&](int root, vector<int> &d)
    {
        queue<int> q;
        q.push(root);
        d[root] = 0;
        while (!q.empty())
        {
            int u = q.front();
            visited[u] = true;
            dia = max(dia, d[u]);
            if (d[u] > max_d)
            {
                max_d = d[u];
                leaf1 = u;
            }
            q.pop();
            for (int v : adj[u])
            {
                if (d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    };

    bfs(root, d);
    bfs(leaf1, d1);
    return dia;
}

void solve()
{
    cin >> n >> m >> num_q;

    Dsu dsu(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.join(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 0; u < n; u++)
    {
        if (visited[u])
            continue;
        int root = dsu.findRoot(u);
        redis[root] = getDiameter(adj, n, root);
    }

    while (num_q-- > 0)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u;
            cin >> u;
            u--;
            cout << redis[dsu.findRoot(u)] << "\n";
        }
        else
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            u = dsu.findRoot(u);
            v = dsu.findRoot(v);
            if (u == v)
                continue;
            int dia_u = redis[u];
            int dia_v = redis[v];
            // cerr << u + 1<< " " << v + 1 << " : " << dia_u << " " << dia_v << "\n";
            int new_dia = max({(dia_u + 1) / 2 + (dia_v + 1) / 2 + 1, dia_u, dia_v});
            redis[u] = redis[v] = new_dia;
            dsu.join(u, v);

            // cerr << u + 1 << " " << v + 1 << "\n";
            // for (int i = 0; i < n; i++)
            // {
            //     cerr << i + 1 << " " << redis[dsu.findRoot(i)] << '\n';
            // }
            // cerr << "\n\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}