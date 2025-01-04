
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
    int cnt = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        int mi = a[i];
        int ma = a[i];
        if (i < a.size() - 1)
        {
            mi = min(a[i], a[i + 1]);
            ma = max(a[i], a[i + 1]);
        }
        if (mi + mi > ma)
        {
            cnt++;
            i++;
        }
    }
    if (cnt >= 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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