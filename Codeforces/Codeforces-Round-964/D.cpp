
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
    string s, t;
    cin >> s >> t;
    int id = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == t[id] || s[i] == '?')
        {
            if (s[i] == '?')
            {
                s[i] = t[id];
            }
            id++;
        }
        if (id == t.size())
        {
            cout << "YES\n";
            fu(z, 0, s.size() - 1)
            {
                if (s[z] == '?')
                {
                    s[z] = 'a';
                }
            }
            cout << s << "\n";
            return;
        }
    }
    cout << "NO\n";
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