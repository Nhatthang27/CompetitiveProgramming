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
ll a[MAX];

void enter() {
    cin >> n;
    fu(i, 1, n) {
        cin >> a[i];
    }
}

void solve() {
    ll l = 1;
    while(l + 1 <= n && a[l + 1] == a[l]) l++;

    ll r = n;
    while(r - 1 >= 1 && a[r - 1] == a[r]) r--;

    ll res;
    if (a[l] != a[r]) {
        res = min(n - l, r - 1);
    } else {
        if (l < r) {
            res = n - l - (n - r + 1);
        } else {
            res = 0;
        }
    }
    cout <<  res << "\n";
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




