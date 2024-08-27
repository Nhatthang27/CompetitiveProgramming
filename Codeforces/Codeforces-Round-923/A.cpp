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
string s;

void enter() {
    cin >> n;
    cin >> s;
}

void solve() {
    ll l, r;
    l = r = -1;
    fu(i, 0, s.size() - 1) {
        if (s[i] == 'B') {
            l = i;
            break;
        }
    }

    fd(i, s.size() - 1, 0) {
        if (s[i] == 'B') {
            r = i;
            break;
        }
    }
    if (l == -1) {
        cout << 0 << "\n";
    } else {
        cout << r - l + 1 << "\n";
    }

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


