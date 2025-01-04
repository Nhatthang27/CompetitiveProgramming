#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << n * (n + 1) / 2 - sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}