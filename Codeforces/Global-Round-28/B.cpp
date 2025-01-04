
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int val = 1;
    int id = k;
    while (id <= n)
    {
        a[id] = val;
        val++;
        id += k;
    }

    int newVal = n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            cout << newVal << " ";
            newVal--;
        }
        else
            cout << a[i] << " ";
    }
    cout << "\n";
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