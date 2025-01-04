
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

const int LIMIT = 30;
void solve()
{
    int l, r, G;
    cin >> l >> r >> G;

    int minX = (l + G - 1) / G;
    int maxX = r / G;

    pair<int, int> ans = {-1, -1};

    for (int i = 0; i <= LIMIT; i++)
    {
        for (int j = 0; j <= LIMIT; j++)
        {
            int x = minX + i;
            int y = maxX - j;
            if (gcd(x, y) == 1 && x <= y)
            {
                if (ans.first == -1 || y - x > ans.second - ans.first)
                {
                    ans = {x, y};
                }
            }
        }
    }
    if (ans.first != -1)
    {
        cout << ans.first * G << " " << ans.second * G << endl;
        return;
    }
    cout << "-1 -1\n";
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