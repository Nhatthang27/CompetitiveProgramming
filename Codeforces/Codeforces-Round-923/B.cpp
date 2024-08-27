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
ll cnt[30];
ll a[MAX];
void enter() {
    cin >> n;
    fu(i, 1, n) {
        cin >> a[i];
    }
    fu(i, 0, 25) {
        cnt[i] = 0;
    }
}

void solve() {
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j <= 25; j++) {
            if (cnt[j] == a[i]) {
                cout << char(j + 'a');
                cnt[j]++;
                break;
            }
        }

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



