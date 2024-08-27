#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll n, k, a[MAX];
ll t;

void enter() {
    cin >> n >> k;
}

void solve() {
    string res = "";
    fu(j, 1, n)
    fu(i, 0, k - 1) {
        res += 'a' + i;
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


