#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e5 + 7;

int t;
char s1[MAX], s2[MAX];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t-->0)
    {
    	ll n;
        cin >> n;
        fu(i, 1, n) cin >> s1[i];
        fu(i, 1, n) cin >> s2[i];
        ll cnt0, cnt1;
        cnt0 = cnt1 = 0;
        fu(i, 1, n) {
        	if (s1[i] != s2[i]) {
        		if(s1[i] == '1') cnt1++;
        		else cnt0++;
			}
		}
		cout << max(cnt0, cnt1) << "\n";
    }
}
