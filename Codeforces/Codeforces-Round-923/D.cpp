#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll t, n, q;
ll a[MAX];
ll bef[MAX];

void enter() {
    cin >> n;
    fu(i, 1, n) {
        cin >> a[i];
        if (i == 1) {
            bef[i] == 0;
        } else {
            if (a[i] != a[i - 1]) {
                bef[i] = i - 1;
            } else {
                bef[i] = bef[i - 1];
            }
        }
    }
}

void solve() {
    cin >> q;
    while(q --> 0) {
            ll l, r;
        cin >> l >> r;
        if (bef[r] < l) {
            cout << -1 << " " << -1 << "\n";
        } else {
            cout << bef[r] << " " << r << "\n";
        }
    }
//    cout << "\n";
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





