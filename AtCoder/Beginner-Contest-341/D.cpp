#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll INF = 1e18;

ll a, b, k;

ll cnt(ll k, ll lcm) {
    return k / a + k / b - 2 * (k / lcm);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> a >> b >> k;
    ll l = 1;
    ll r = INF;
    ll lcm = a * b / __gcd(a, b);
    ll res;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(cnt(mid, lcm) > k) {
            r = mid - 1;
        } else if(cnt(mid, lcm) < k) {
            l = mid + 1;
        } else {
            res = mid;
            r = mid - 1;
        }
    }
    cout << res;
}
