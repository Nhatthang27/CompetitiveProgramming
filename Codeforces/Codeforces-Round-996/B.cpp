
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int lower = 0, greater = LONG_LONG_MAX;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
            lower++, tmp = b[i] - a[i];
        else
            greater = min(greater, a[i] - b[i]);
    }
    if (lower == 0)
    {
        cout << "YES" << endl;
    }
    else if (lower == 1)
    {
        if (greater >= tmp)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}