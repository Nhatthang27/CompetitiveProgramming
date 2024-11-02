
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
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>());
    // clear the buffer
    cin.ignore();
    fu(i, 1, n - 1)
    {
        string s;
        getline(cin, s);
        // cout << i << " " << s << endl;
        istringstream ss(s);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }
        for (auto x : tokens)
        {
            a[i].push_back(stoi(x));
            // cout << i << " " << stoi(x) << endl;
        }
    }

    vector<int> dep(n + 1, 0);
    // dfs to get the parent of each node
    function<void(int, int)> dfs = [&](int u, int p)
    {
        // cout << u << " " << p << endl;
        for (auto v : a[u])
        {
            if (v != p)
            {
                // cout << u << " " << v << endl;
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
        }
    };
    dfs(1, 0);
    int x;
    cin >> x;
    // cout << x << " " << dep[x] << endl;
    // fu(i, 1, n)
    // {
    //     cout << i << " " << dep[i] << endl;
    // }
    vector<int> res;
    fu(u, 1, n)
    {

        if (dep[u] == dep[x] && u != x)
        {
            res.push_back(u);
        }
    }
    if (res.empty())
    {
        cout << "-1\n";
        return;
    }
    sort(res.begin(), res.end());
    for (auto x : res)
    {
        cout << x << " ";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    // cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}