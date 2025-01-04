
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

    auto isLeadingZero = [&](string s)
    {
        if ((int)s.size() == 1)
            return false;
        return s[0] == '0';
    };

    auto isDigit = [&](char c)
    {
        return ('0' <= c && c <= '9');
    };

    auto check = [&](string s) -> int
    {
        int id = 0;
        if (!isDigit(s[id]))
            return LONG_LONG_MAX;

        int value = 0;
        int sign = 1;
        string num = "";

        while (id < (int)s.size())
        {
            // case 2: gặp dấu nhưng chưa có số
            if (!isDigit(s[id]) && num.empty())
            {
                return LONG_LONG_MAX;
            }

            // case 3: đã có dấu đang đi tìm số
            if (isDigit(s[id]))
            {
                num += s[id];
                if (num.size() > 10)
                    return LONG_LONG_MAX;
                if (id == (int)s.size() - 1)
                {
                    if (isLeadingZero(num))
                        return LONG_LONG_MAX;
                    if (sign == 1)
                        value += stoll(num);
                    else if (sign == 2)
                        value -= stoll(num);
                    break;
                }
            }

            // case 4: gặp dấu đã có số
            if (!isDigit(s[id]) && !num.empty())
            {
                if (id == (int)s.size() - 1 || isLeadingZero(num))
                {
                    return LONG_LONG_MAX;
                }
                int x = stoll(num);
                if (sign == 1)
                    value += x;
                else if (sign == 2)
                    value -= x;

                num = "";
                sign = s[id] == '+' ? 1 : 2;
            }

            id++;
        }
        return value;
    };

    string s;
    cin >> s;

    string left = "", right = "";

    auto split = [&](string s)
    {
        string left = "", right = "";
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '=')
                break;
            left += s[i];
        }
        for (int i = left.size() + 1; i < s.size(); i++)
        {
            right += s[i];
        }
        return pair<string, string>({left, right});
    };

    pair<string, string> cc = split(s);
    left = cc.first;
    right = cc.second;

    int left_val = check(left);
    int right_val = check(right);
    if (left_val != LONG_LONG_MAX && right_val != LONG_LONG_MAX && left_val == right_val)
    {
        cout << "Correct";
        return;
    }

    int n = s.size();
    // cerr << "s: " << s << "\n";
    for (int i = 0; i < n; i++)
    {
        if (!isDigit(s[i]))
            continue;
        char c = s[i];
        string new_s = s;
        new_s.erase(i, 1);
        // cerr << new_s << "\n";
        for (int j = 0; j <= n - 1; j++)
        {
            string tmp = new_s;
            tmp.insert(tmp.begin() + j, c);

            cc = split(tmp);
            left = cc.first;
            right = cc.second;
            left_val = check(left);
            right_val = check(right);
            // cerr << left << " " << right << "\n";
            if (left_val != LONG_LONG_MAX && right_val != LONG_LONG_MAX && left_val == right_val)
            {
                cout << left << "=" << right;
                return;
            }
        }
    }
    cout << "Impossible";
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