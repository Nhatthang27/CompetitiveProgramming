
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
    int cnt = 0;
    int n;
    cin >> n;
    map<char, int> mp;
    map<char, int> real;
    fu(i, 1, n)
    {
        char c;
        int x;
        cin >> c >> x;
        mp[c] = x;
    }

    // int cnts = 0, cnto = 0;
    // int tmp = 0;
    fu(i, 0, s.size() - 1)
    {
        // cnts += (s[i] == 's');
        // cnto += (s[i] == 'o');
        if (mp[s[i]] == 0)
        {
            // tmp++;
            cnt++;
        }
        else
        {
            if (real[s[i]] % mp[s[i]] == 0)
            {
                cnt += 2;
                real[s[i]] += 2;
            }
            else
            {
                cnt++;
                real[s[i]]++;
            }
        }
    }
    // cout << tmp << endl;

    // cout << cnts << " " << cnto << endl;
    // cout << s.size() << endl;
    cout << cnt << endl;

    // ss s s
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