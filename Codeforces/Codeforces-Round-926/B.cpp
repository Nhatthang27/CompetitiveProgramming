#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll n;
ll t;
ll k;

void enter() {
    cin >> n >> k;
}
void solve() {
    ll numPoint = k / 2 + (k % 2 == 0 ? 0 : 1);
    ll totalPoint = n * 2 - 2;
    if (numPoint > totalPoint) {
        ll du = (k - totalPoint * 2);
        cout << du + totalPoint << "\n";
    } else {
        cout << numPoint << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    while(t --> 0) {
        enter();
        solve();
    }
}



