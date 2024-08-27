
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
    int n;
    cin >> n;
    string up, down;
    cin >> up;
    cin >> down;

    int cnt = 0;
    for (int i = 1; i < up.size() - 1; i++) {
        if (up[i] == 'x') continue;
        if (up[i - 1] == '.' && up[i + 1] == '.' && down[i] == '.' && down[i - 1] == 'x' && down[i + 1] == 'x') cnt++;
    }
    for (int i = 1; i < down.size() - 1; i++) {
        if (down[i] == 'x') continue;
        if (down[i - 1] == '.' && down[i + 1] == '.' && up[i] == '.' && up[i - 1] == 'x' && up[i + 1] == 'x') cnt++;
    }
    cout << cnt << "\n";
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

