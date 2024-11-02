
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
    int a, b;
    cin >> a >> b;
    int cnt = 1;
    if (a > b)
        swap(a, b);
    while ((a != 1 || b != 1) && a != b)
    {
        int tmp = a;
        a = b - a;
        b = tmp;
        if (a > b)
            swap(a, b);
        // cout << a << " " << b << endl;
        cnt++;
    }
    cout << cnt;
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