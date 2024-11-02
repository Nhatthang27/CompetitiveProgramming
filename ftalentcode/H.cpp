
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
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    f = a[f];
    sort(a.begin() + 1, a.end(), greater<int>());

    if (a[k] > f)
    {
        cout << "NO\n";
    }
    else if (a[k] < f)
    {
        cout << "YES\n";
    }
    else
    {
        if (k == n)
        {
            cout << "YES\n";
            return;
        }
        if (a[k + 1] == f)
        {
            cout << "MAYBE\n";
        }
        else
        {
            cout << "YES\n";
        }
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

// 5 5 3
// 4 2 1 3 5

// f = 1

//     5 4 3 2 1
// 2 1 1
// 2 1

// f = 2
