
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'p')
            a[i] = 'q';
        else if (a[i] == 'q')
            a[i] = 'p';
    }
    reverse(a.begin(), a.end());
    cout << a << "\n";
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