#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MASK(i) (1LL << i)

using namespace std;
const ll MAX = 1e6 + 7;
const ll INF = 1e18;

ll t, n, a[MAX];
ll f[200];

void prepare() {
    f[0] = 0;
    f[1] = 2;
    f[2] = 3;
    fu(i, 3, 90) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

void solve() {
    cin >> t;
    while(t --> 0) {
        cin >> n;
        cout << upper_bound(f + 1, f + 91, n) - f - 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
prepare();
    solve();
}



