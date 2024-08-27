
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    fu(i, 1, n - 1)
    {
        if (s[i] == 'X' && s[i - 1] == 'I')
            cnt++;
    }
    if (s[n - 1] == 'I')
        cnt++;
    if (cnt <= 1)
        cout << "WIN\n";
    else
        cout << "LOSE\n";
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