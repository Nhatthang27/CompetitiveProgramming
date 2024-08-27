#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll t, a[MAX];
ll n;
string s;

void enter() {
    cin >> s;
}

void solve() {
    ll ca, cb;
    ca = cb = 0;
    fu(i, 0, s.size() - 1) {
        if (s[i] == 'A') ca++;
        if (s[i] == 'B') cb++;
    }
    if (ca > cb) cout << "A\n";
    else cout << "B\n";
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
