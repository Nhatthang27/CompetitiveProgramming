#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 2e5 + 7;

ll t;
ll n, m;
ll a[MAX];
ll b[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t-->0)
    {
    	cin >> n >> m;
    	fu(i, 1, n) cin >> a[i];
    	fu(i, 1, m) cin >> b[i];
    	sort(a + 1, a + n + 1);
    	sort(b + 1, b + m + 1);
    	ll ha = 1, ta = n;
    	ll hb = 1, tb = m;
    	ll res = 0;
    	
    	while(ha <= ta) {
    		ll tmp_h = abs(b[tb] - a[ha]);
    		ll tmp_t = abs(b[hb] - a[ta]);
    		if (tmp_h > tmp_t) {
    			res += tmp_h;
//    			cout << b[tb] << " ";
    			ha++;
    			tb--;
			} else {
				res += tmp_t;
//				cout << b[hb] << " ";
				ta--;
				hb++;
			}
		}
		
		cout << res << "\n";
    }
}
