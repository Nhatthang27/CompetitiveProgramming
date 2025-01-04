
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    vector<int> sum(2 * n + 1, 0);
    vector<int> dm(2 * n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        if (l[i] == r[i])
        {
            dm[l[i]]++;
            sum[l[i]] = 1;
        }
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (l[i] == r[i])
        {
            cout << (dm[l[i]] == 1);
        }
        else
        {
            int cnt = sum[r[i]] - sum[l[i] - 1];
            cout << (cnt < (r[i] - l[i] + 1) ? 1 : 0);
        }
    }

    cout << "\n";
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