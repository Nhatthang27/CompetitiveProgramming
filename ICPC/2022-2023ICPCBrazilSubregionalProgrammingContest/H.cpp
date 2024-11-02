
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    fu(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> comp(n + 1, -1);
    // comp[u] mean u belong to component comp[u]
    // tarjan algorithm to find strongly connected component and assign each vertex to a component
    vector<int> low(n + 1, 0), num(n + 1, 0);
    stack<int> st;
    vector<bool> inStack(n + 1, false);
    int cnt = 0;
    int numComp = 0;
    function<void(int)> tarjan = [&](int u)
    {
        low[u] = num[u] = ++cnt;
        st.push(u);
        inStack[u] = true;
        for (int v : adj[u])
        {
            if (num[v] == 0)
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v])
            {
                low[u] = min(low[u], num[v]);
            }
        }
        if (low[u] == num[u])
        {
            numComp++;
            int v;
            do
            {
                v = st.top();
                st.pop();
                inStack[v] = false;
                comp[v] = numComp;
            } while (v != u);
        }
    };

    fu(i, 1, n)
    {
        if (num[i] == 0)
            tarjan(i);
    }

    if (numComp == 1)
    {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> adjComp(numComp + 1, vector<int>());
    vector<int> inDeg(numComp + 1, 0);
    vector<int> outDeg(numComp + 1, 0);
    fu(u, 1, n)
    {
        for (int v : adj[u])
        {
            if (comp[u] != comp[v])
            {
                adjComp[comp[u]].push_back(comp[v]);
                inDeg[comp[v]]++;
                outDeg[comp[u]]++;
            }
        }
    }

    int cntIn = 0, cntOut = 0;
    fu(i, 1, numComp)
    {
        if (inDeg[i] == 0)
            cntIn++;
        if (outDeg[i] == 0)
            cntOut++;
    }
    cout << max(cntIn, cntOut) << endl;
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