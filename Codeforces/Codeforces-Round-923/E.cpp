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
ll k;

void enter() {
    cin >> n >> k;
}

void solve() {
    fu(i, 1, n) a[i] = 0;
    ll up = n;
    ll down = 1;
    bool isOdd = true;
    fu(i, 1, k) {
        for(ll j = i; j <= n; j += k) {
            if (isOdd) a[j] = up--;
            else a[j] = down++;
        }
        isOdd = !isOdd;
    }
    fu(i, 1, n) {
        cout << a[i] << " ";
    }
    cout << "\n";
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






