#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

unordered_map<ll, ll> mp;
ll n;

ll cal(ll n) {
    if (n == 1) {
        return 0;
    }
    if (mp[n] != 0) {
        return mp[n];
    }
    ll x1 = n / 2;
    ll x2 = (n % 2 == 0 ? x1 : x1 + 1);
    return mp[n] = cal(x1) + cal(x2) + n;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> n;
    cout << cal(n);
}


