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
    fu(i, 1, n) cin >> a[i];
}
void solve() {
    ll sum = 0;
    sort(a + 1, a + n + 1);
    fu(i, 2, n) {
        sum += a[i] - a[i - 1];
    }
    cout << sum << "\n";
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


