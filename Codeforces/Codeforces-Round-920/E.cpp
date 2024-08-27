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
ll row, col;
ll a, b;
ll x, y;

string solve(ll row, ll col, ll a, ll b, ll x, ll y) {
	ll dis = x - a - 1;
	if (dis < 0) {
		return "Draw";
	}
	if (dis % 2 == 0) {
		ll step = dis / 2;
		if (y < b) {
			y = max((ll)1, y - step);
			b = max((ll)1, b - step);
		} else {
			y = min(col, y + step);
			b = min(col, b + step);
		}
		if (abs(b - y) > 1) {
			return "Draw";
		} else {
			return "Alice";
		}
	} else {
		ll step = dis / 2;
		if (b < y) {
			b = max((ll)1, b - step - 1);
			y = max((ll)1, y - step);
		} else {
			b = min(col, b + step + 1);
			y = min(col, y + step);
		}
		if (abs(b - y) > 1) {
			return "Draw";
		} else {
			return "Bob";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t-->0)
    {
    	cin >> row >> col >> a >> b >> x >> y;
		cout << solve(row, col, a, b, x, y) << "\n";
    }
}
