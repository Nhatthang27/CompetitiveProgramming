
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    bool isReverse = false;
    if (a < b)
    {
        swap(a, b);
        isReverse = true;
    }
    if (a == 1 && b == 1 && n >= 2 && n <= 3) {
        cout << "NO\n";
        return;
    }
    if (b == 1)
    {
        int numComp = n;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i + 1 == j && numComp > a)
                {
                    ans[i][j] = ans[j][i] = 1;
                    numComp--;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << 0;
                else
                    cout << (ans[i][j] ^ isReverse);
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "NO\n";
        return;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}