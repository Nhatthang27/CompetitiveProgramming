
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
    if (n % 2 == 1)
    {
        if (n < 27)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            vector<int> res(n + 1);
            res[1] = res[10] = res[26] = 1;
            res[23] = res[27] = 2;
            int val = 3;
            bool isInc = false;
            fu(i, 1, n)
            {
                if (res[i] == 0)
                {
                    res[i] = val;
                    if (isInc)
                    {
                        val++;
                    }
                    isInc = !isInc;
                }
            }
            fu(i, 1, n)
            {
                cout << res[i] << " ";
            }
            cout << endl;
            return;
        }
    }
    fu(i, 1, n / 2)
    {
        cout << i << " " << i << " ";
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