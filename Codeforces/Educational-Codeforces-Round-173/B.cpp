
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    cout << 1 << " ";
    if (d % 3 == 0 || n >= 3)
        cout << 3 << " ";
    if (d % 5 == 0)
        cout << 5 << " ";
    if (d % 7 == 0 || n >= 3)
        cout << 7 << " ";
    if (d % 9 == 0 || n >= 6 || (n >= 3 && d % 3 == 0))
        cout << 9 << " ";
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