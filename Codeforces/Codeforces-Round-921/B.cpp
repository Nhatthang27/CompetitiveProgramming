#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll n, a[MAX];
ll t, k;

void enter() {
    cin >> n >> k;
    ll res = 0;
    fu(g, 1, sqrt(n) + 1) {
        if (n % g != 0) continue;
        if (g * k <= n) {
            res = max(g, res);
        }
        if ((n / g) * k <= n)
        res = max(res, (n / g));
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    while(t --> 0) {
        enter();
    }
}


