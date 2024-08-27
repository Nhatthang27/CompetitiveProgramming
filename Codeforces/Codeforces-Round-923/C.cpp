#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll na, nb;
ll t, k;
ll a[MAX];
ll b[MAX];
ll check[MAX];

void enter() {
    cin >> na >> nb >> k;
    fu(i, 1, k) check[i] = 0;
    fu(i, 1, na) cin >> a[i];
    fu(i, 1, nb) cin >> b[i];
}

void solve() {
    ll cntA = 0;
    ll cntB = 0;

    fu(i, 1, na) {
        if (a[i] <= k && check[a[i]] == 0) {
            check[a[i]] = 1;
            cntA++;
        }
    }
    if (cntA < k / 2) {
        cout << "NO\n";
        return;
    }
    fu(i, 1, nb) {
        if (b[i] <= k && check[b[i]] <= 1) {
            check[b[i]] = 2;
            cntB++;
        }
    }
    if (cntB < k / 2) {
        cout << "NO\n";
        return;
    }
    fu(i, 1, k) {
        if(check[i] == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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




