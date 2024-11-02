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
    vector<pair<double, double>> tri1(3), tri2(3);
    fu(i, 0, 2) cin >> tri1[i].ff >> tri1[i].ss;
    fu(i, 0, 2) cin >> tri2[i].ff >> tri2[i].ss;

    // check if any point of tri1 is inside tri2 or vice versa
    bool flag = false;
    fu(i, 0, 2)
    {
        if (tri1[i].ff >= tri2[0].ff && tri1[i].ff <= tri2[2].ff && tri1[i].ss >= tri2[0].ss && tri1[i].ss <= tri2[2].ss)
        {
            flag = true;
            break;
        }
    }

    fu(i, 0, 2)
    {
        if (tri2[i].ff >= tri1[0].ff && tri2[i].ff <= tri1[2].ff && tri2[i].ss >= tri1[0].ss && tri2[i].ss <= tri1[2].ss)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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