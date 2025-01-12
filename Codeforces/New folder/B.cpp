
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int cnt = 1;
    vector<int> val;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            val.push_back(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    val.push_back(cnt);
    sort(val.begin(), val.end());
    int ans = 0;
    for (int i = 0; i < val.size(); i++)
    {
        if (k >= val[i])
        {
            k -= val[i];
        }
        else
        {
            ans++;
        }
    }
    cout << max(1LL, ans) << "\n";
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