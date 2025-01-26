
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int k = abs(a - b);
    if (k % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}