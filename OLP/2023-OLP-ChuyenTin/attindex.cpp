
#include <bits/stdc++.h>
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 1e5 + 7;
string s;
int p;
int numQ;
int n;

void enter()
{
    cin >> p;
    cin >> s;
    n = (int)s.size();
    s = " " + s;
    cin >> numQ;
}

bool isSub1()
{
    return ((int)s.size() <= 101 && numQ <= 100);
}

void sub1()
{

    // auto get_integer = [&](string s)
    // {
    //     while (!s.empty() && s[0] == '0')
    //         s.erase(0, 1);
    //     int res = 0;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         res = res * 10 + (s[i] - '0');
    //     }
    //     return res;
    // };

    for (int i = 1; i <= numQ; i++)
    {
        int l, r;
        cin >> l >> r;
        int res = 0;
        for (int li = l; li <= r; li++)
        {
            int val = 0;
            for (int ri = li; ri <= r; ri++)
            {
                val = val * 10 + (s[ri] - '0');
                if (val % p == 0)
                {
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
}
void sub2()
{

    vector<int> sum(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            sum[i] = sum[i - 1] + i;
            cnt[i] = cnt[i - 1] + 1;
        }
        else
        {
            sum[i] = sum[i - 1];
            cnt[i] = cnt[i - 1];
        }
    }

    for (int q = 1; q <= numQ; q++)
    {
        int l, r;
        cin >> l >> r;
        int res = (sum[r] - sum[l - 1]) - (cnt[r] - cnt[l - 1]) * (l - 1);
        cout << res << "\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    if (isSub1())
    {
        sub1();
    }
    else if (p == 2)
    {
        sub2();
    }
    else
    {
        cout << 1 / 0;
    }
}
