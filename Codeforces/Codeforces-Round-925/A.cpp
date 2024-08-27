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

char convert(ll i) {
    return char('a' + i);
}
void solve() {
    ll sum = 0;
    cin >> sum;
    fu(i, 1, 26) {
        fu(j, 1, 26) {
            if (sum - (i + j) <= 26) {
                cout << convert(i - 1) << convert(j - 1) << convert(sum - (i + j) - 1) << "\n";
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    while(t --> 0) {
        solve();
    }
}


