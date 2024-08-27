#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

void solve() {
    ll n, k, x, a;
    cin >> k >> x >> a;

    int sum = 0;
    int numCoin = a;
    fu(i, 1, x) {
        int bet = sum / (k - 1) + 1;
        numCoin -= bet;
        // cout << i << " " << bet << " " << numCoin << "\n";
        if (numCoin <= 0) {
            cout << "NO\n";
            return;
        } else if (i == x) {
            if (numCoin * k <= a || numCoin + bet * k <= a) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
            return;
        }
        sum += bet;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
