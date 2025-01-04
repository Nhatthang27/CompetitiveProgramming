
#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b)
{
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

pair<int, int> solve_coprime_pair(int L, int R)
{
    if (gcd(L, R) == 1)
    {
        return {L, R};
    }

    for (int i = 0; i <= R - L; ++i)
    {
        if (gcd(L, R - i) == 1)
        {
            return {L, R - i};
        }
        if (gcd(L + i, R) == 1)
        {
            return {L + i, R};
        }
    }
    return {-1, -1};
}

void solve()
{
    int l, r, g;
    cin >> l >> r >> g;

    int L = (l + g - 1) / g;
    int R = r / g;

    // cerr << L << " " << R << endl;

    pair<int, int> ans = solve_coprime_pair(L, R);
    if (ans.first == -1)
    {
        cout << "-1 -1" << endl;
    }
    else
    {
        cout << ans.first * g << " " << ans.second * g << endl;
    }
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