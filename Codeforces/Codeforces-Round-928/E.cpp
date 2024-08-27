#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll t;
ll n, k;

ll getMask(ll n) {
    return (ll)(1LL << n);
}

void enter() {
    cin >> n >> k;
}

void solve() {
    if (k <= (n + 1) / 2) {
        ll ans = k * 2;
        cout << ans - 1 << "\n";
        return;
    }

    fu(i, 0, 31) {
        ll linthoi = getMask(i);
        ll oldK = k;
        ll cc = (n - linthoi) / (linthoi * 2) + 1;
        if (k - cc > 0) k -= cc;
        else
         {
             k -= cc;
            cout << linthoi + (oldK - 1) * 2 * linthoi << "\n";
            return;
        }
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

