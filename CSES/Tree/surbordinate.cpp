#include <bits/stdc++.h>
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
const int MAX = 2e5 + 7;

int numNode, numEdge;
vector<int> adj[MAX];
int cnt[MAX];

void enter()
{
    cin >> numNode;
    numEdge = numNode - 1;
    fu(u, 2, numNode)
    {
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int par)
{
    for (int v : adj[u])
    {
        if (v != par)
        {
            dfs(v, u);
            cnt[u] += cnt[v] + 1;
        }
    }
}

void solve()
{
    dfs(1, -1);
    for (int i = 1; i <= numNode; i++)
    {
        cout << cnt[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    solve();
}