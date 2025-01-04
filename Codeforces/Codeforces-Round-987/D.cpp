
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


struct Dsu {
    vector<int> root, ma;

    Dsu(int n, vector<int> a) {
        root.assign(n + 1, -1);
        for (int u = 1; u <= n; u++) {
            root[u] = u;
        }
        ma = a;
    }

    int findRoot(int u) {
        return root[u] = (root[u] == u ? u : findRoot(root[u]));
    }

    bool join(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v) {
            if (ma[u] < ma[v])
                swap(u, v);
            root[v] = u;
            ma[u] = max(ma[u], ma[v]);
            return true;
        } else {
            return false;
        }
    }

    int getMax(int u) {
        return ma[findRoot(u)];
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> val(n + 1);
    fu(i, 1, n)
    {
        cin >> val[i];
    }

    Dsu dsu(n, val);
    set<pii> s;
    fd(i, n, 1)
    {
        auto it = s.lower_bound({val[i], i});
        //get previous element
        if (it != s.begin())
        {
            it--;
            if (it->ff < val[i])
            {
                dsu.join(i, it->ss);
            }
        }
        s.insert({val[i], i});
    }

    stack<int> st;
    // fd(i, n, 1)
    // {
    //     while (!st.empty() && val[st.top()] >= val[i])
    //     {
    //         st.pop();
    //     }
    //     if (!st.empty())
    //     {
    //         dsu.join(i, st.top());
    //     }
    //     st.push(i);
    // }

    // while(!st.empty()) st.pop();


    fu(i, 1, n)
    {
        while (!st.empty() && val[st.top()] <= val[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            dsu.join(i, st.top());
        }
        st.push(i);
    }


    vector<int> ans(n + 1, -1);
    fu(i, 1, n)
    {
        ans[i] = dsu.getMax(i);
    }
    fu(i, 1, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

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