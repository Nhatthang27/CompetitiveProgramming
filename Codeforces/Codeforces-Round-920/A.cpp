#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;

int t;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t-->0)
    {
        pll a[4];
        cin >> a[0].ff >> a[0].ss;
        cin >> a[1].ff >> a[1].ss;
        cin >> a[2].ff >> a[2].ss;
        cin >> a[3].ff >> a[3].ss;

        ll res = 100000000000000;
        fu(i, 1, 3)
        {
            ll area = (a[0].ff - a[i].ff) * (a[0].ff - a[i].ff) + (a[0].ss - a[i].ss) * (a[0].ss - a[i].ss);
            res = min(res, area);
        }
        cout << res << "\n";
    }
}
