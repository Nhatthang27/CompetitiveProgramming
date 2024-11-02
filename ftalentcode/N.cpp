
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
    int x, y;
    cin >> x >> y;

    auto checkPalin = [&](int x) -> bool
    {
        string s = to_string(x);
        int n = s.size();
        fu(i, 0, n / 2)
        {
            if (s[i] != s[n - i - 1])
            {
                return false;
            }
        }
        return true;
    };

    auto checkSnake = [&](int x) -> bool
    {
        string s = to_string(x);
        int n = s.size();
        if (n == 1)
            return true;
        if (s[1] <= s[0])
            return false;
        fu(i, 2, n - 2)
        {
            if (s[i] >= s[i - 1] && s[i] <= s[i + 1])
                return false;
            if (s[i] <= s[i - 1] && s[i] >= s[i + 1])
                return false;
        }
        return true;
    };

    vector<int> res;
    fu(i, x, y)
    {
        if (checkPalin(i) && checkSnake(i))
        {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    if (res.size() > 0)
    {
        cout << "[";
        fu(i, 0, res.size() - 1)
        {
            cout << res[i];
            if (i != res.size() - 1)
                cout << ", ";
        }
        cout << "]";
    }
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