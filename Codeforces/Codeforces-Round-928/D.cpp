#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 2e5 + 7;

ll t;
ll n;
ll a[MAX];
map<ll, ll> cnt;

ll getMask(ll n) {
    return (ll)(1LL << n);
}

void enter() {
    cin >> n;
    cnt.clear();
    fu(i, 1, n) {
        cin >> a[i];
    }
}

void solve() {
    ll res = 0;
    ll mask = getMask(31) - 1;
    fu(i, 1, n) {
        cnt[a[i]]++;
    }
    fu(i, 1, n) {
        ll x = a[i];
        if (cnt[mask ^ x]) {
            cnt[mask ^ x]--;
            res++;
        }
    }
    cout << res / 2 + (n - res - (res % 2 == 0 ? 0 : 1)) << "\n";
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


