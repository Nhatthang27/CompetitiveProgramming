
#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 1;
ll sieve[MAX + 7];

bool check(ll x, ll a, ll b) {
    ll a1 = a;
    ll b1 = b;
    for (ll a1 = 1; a1 <= x; a1 *= a) {
        for (ll b1 = 1; a1 * b1 <= x; b1 *= b) {
            if (a1 * b1 == x) {
                return true;
            }
        }
    }
    return false;
}
void solve() {
    ll a, b, l;
    ll res = 0;
    cin >> a >> b >> l;
    fu(k, 1, sqrt(l)) {
        if (l % k == 0) {

            if (k == l / k) {
                res += check(k, a, b);
            } else {
                res += check(l / k, a, b) + check(k, a, b);
            }
            // cout << l / k << " " << k << " " << res << "\n";
        }
    }
    cout << res << "\n";
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}