
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (n == 4)
    {
        cout << -1 << endl;
        return;
    }
    if (n > 4 && n - 1 + 2 > k)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n);
    ans[0] = a;
    ans[n - 1] = b;
    ans[1] = c;
    ans[n - 2] = d;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (i != a && i != b && i != c && i != d)
        {
            pq.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            ans[i] = pq.top();
            pq.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    swap(ans[0], ans[1]);
    swap(ans[n - 1], ans[n - 2]);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}