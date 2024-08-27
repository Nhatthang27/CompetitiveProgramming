#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

bool check(string s)
{
    if (s[0] < 'A' || s[0] > 'Z')
    {
        return false;
    }
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //    freopen("input.inp", "r", stdin);
    string s;
    cin >> s;
    cout << (check(s) ? "Yes" : "No");
}
