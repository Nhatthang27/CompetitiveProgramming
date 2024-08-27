
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
    int n, k;
    cin >> n >> k;
    vector<char> a(n + 1);
    int cnt = 0;
    fu(i, 1, n)
    {
        cin >> a[i];
        if (a[i] == '1')
            cnt++;
    }

    if (n == 1)
    {
        if (a[1] == '1' && k == 1)
        {
            cout << "NO\n";
            return;
        }
        if (a[1] == '0' && k == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    int pos = 0;
    fu(i, 1, n)
    {
        cout << pos + 1 << " ";
        pos = (pos + i) % n;
    }
    cout << "\n";
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