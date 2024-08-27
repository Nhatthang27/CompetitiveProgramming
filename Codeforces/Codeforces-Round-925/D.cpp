#include <bits/stdc++.h>
#include <utility>
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
ll a[MAX], ax[MAX], ay[MAX];
ll x, y;

void enter() {
    cin >> n >> x >> y;
    fu(i, 1, n) {
        cin >> a[i];
        ax[i] = a[i] % x;
        ay[i] = a[i] % y;
    }
}

map< pair<ll, ll>, ll> cnt;
void solve() {
    ll res = 0;
    cnt.clear();
    fu(i, 1, n) {
        if (ax[i] == 0) {
            res += cnt[make_pair(0, ay[i])];
        } else {
            res += cnt[make_pair(x - ax[i], ay[i])];
        }
        cnt[make_pair(ax[i], ay[i])]++;
    }
    cout << res << "\n";
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





