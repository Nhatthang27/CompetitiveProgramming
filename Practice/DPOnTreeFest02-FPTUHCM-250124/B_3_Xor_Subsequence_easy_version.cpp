
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = max(0ll, i - 256 * 2); j < i; j++)
        {
            if ((j ^ a[i]) > (i ^ a[j]))
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}