
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    map<int, int> m;
    m[a + b]++;
    m[c - b]++;
    m[d - c]++;
    cout << max({m[a + b], m[c - b], m[d - c]}) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}