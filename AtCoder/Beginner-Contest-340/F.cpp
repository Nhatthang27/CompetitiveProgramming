#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 2e5 + 7;
const ll INF = 1e18;

void extendedEuclid(ll a, ll b, ll &x, ll &y, ll &d) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(b, a % b, x, y, d);
        ll temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}

void solve() {
    ll a, b, d, x, y;
    cin >> a >> b;
    extendedEuclid(a, b, x, y, d);

    if (2 % d != 0) {
        cout << -1;
    } else {
        ll k = 2 / d;
        cout << y * k << " " << -x * k;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}

