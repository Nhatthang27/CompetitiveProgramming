
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
    int n, m, q;
    cin >> n >> m >> q;
    int l = m, r = m;
    set<int> s;
    s.insert(m);
    for (int i = 1; i <= q; i++)
    {
        int pos;
        cin >> pos;
        if (pos < l)
        {
            l--;
            l = max(l, 1LL);
            s.insert(l);
        }

        else if (pos > r)
        {
            r++;
            r = min(r, n);
            s.insert(r);
        }

        else
        {
            l--;
            r++;
            l = max(l, 1LL);
            r = min(r, n);
            s.insert(l);
            s.insert(r);
            s.insert(1);
            s.insert(n);
        }
        cout << r - l + 1 << " ";
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