
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
    string s;
    cin >> s;

    auto calc = [&](string s)
    {
        int sum = 2;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                sum += 2;
            }
            else
            {
                sum += 1;
            }
        }
        return sum;
    };

    int res = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            char c = 'a' + j;
            string t = s;
            // add c at i
            t.insert(i, 1, c);
            int ss = calc(t);
            if (ss > res)
            {
                res = ss;
                ans = t;
            }
        }
    }
    cout << ans << endl;
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
