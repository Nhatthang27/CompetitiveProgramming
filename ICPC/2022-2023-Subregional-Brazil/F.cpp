
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
    int n, c;
    cin >> n >> c;
    vector<string> a(n + 1);
    fu(i, 1, n) cin >> a[i];

    auto check = [&](string &x, string &y)
    {
        fu(i, 0, c - 1)
        {
            if (x[i] == '*' || y[i] == '*')
                continue;
            if (x[i] != y[i])
                return false;
        }
        return true;
    };

    int ans_num = 0;
    string ans_str = "";
    fu(i, 1, n)
    {
        string res = a[i];
        int idx = 0;
        fu(j, 0, c - 1) if (a[i][j] == '*')
        {
            idx = j;
            break;
        }
        fu(j, 0, 25)
        {
            res[idx] = 'a' + j;
            int cnt = 0;
            fu(k, 1, n)
            {
                if (check(res, a[k]))
                    cnt++;
            }
            if (cnt > ans_num)
            {
                ans_num = cnt;
                ans_str = res;
            }
            else if (cnt == ans_num)
            {
                ans_str = min(ans_str, res);
            }
        }
    }
    cout << ans_str << " " << ans_num;
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