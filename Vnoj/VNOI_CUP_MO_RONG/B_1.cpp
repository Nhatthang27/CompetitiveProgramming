#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e5 + 1;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(4, vector<int>());
    vector<int> m(4, 0);
    fu(i, 1, 3)
    {
        int nz = 0;
        cin >> nz;
        a[i].resize(nz + 1);
        m[i] = nz;
        fd(j, nz, 1)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> xorSum(4, vector<int>(MAX, 0));
    fu(i, 1, 3)
    {
        fu(j, 1, m[i])
        {
            xorSum[i][j] = xorSum[i][j - 1] ^ a[i][j];
        }
    }

    auto check = [&](vector<int> sz)
    {
        if (sz[1] == 0 && sz[2] == 0 && sz[3] == 0)
            return true;
        int sum = xorSum[1][sz[1]] ^ xorSum[2][sz[2]] ^ xorSum[3][sz[3]];
        if (sum != 0)
            return false;
        fu(i, 1, 2)
        {
            if (sz[i] == 0)
                continue;
            fu(j, i + 1, 3)
            {
                if (sz[j] == 0)
                    continue;
                if (a[i][sz[i]] == a[j][sz[j]])
                    return true;
            }
        }
        return false;
    };

    while (q-- > 0)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> sz = {0, m[1] - x, m[2] - y, m[3] - z};
        if (check(sz))
            cout << "MofK\n";
        else
            cout << "Lihwy\n";
    }
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