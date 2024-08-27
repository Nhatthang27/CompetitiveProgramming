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
ll n, f, etime, off;
ll a[MAX];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t-->0)
    {
    	bool res = true;
        cin >> n >> f >> etime >> off;
        fu(i, 1, n) cin >> a[i];
        fu(i, 1, n) {
        	ll tmp = (a[i] - a[i - 1]) * etime;
        	if (tmp > off) {
        		f -= off;
			} else {
				f -= tmp;
			}
			if (f <= 0) {
				res = false;
				break;
			}
		}
		
		if (res) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
    }
}
