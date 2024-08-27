#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MASK(i) (1LL << i)

using namespace std;
const ll MAX = 1e7;
const ll INF = 1e18;

ll n, t;

void solve() {
    cin >> t;
    while(t --> 0) {
        ll res = 0;
        cin >> n;
        fu(x, 1, n) {
            fu(y, x, n) {
                if (__gcd(x, n) * __gcd(y, n) == __gcd(x * y, n)) {
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    solve();
}





