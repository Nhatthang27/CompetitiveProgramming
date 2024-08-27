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
ll avg;

void enter() {
    avg = 0;
    cin >> n;
    fu(i, 1, n) {
        cin >> a[i];
        avg += a[i];
    }
}

string solve() {
    avg = avg / n;
    ll sum = 0;
    fu(i, 1, n) {
        sum  += a[i] - avg;
        if (sum < 0) {
            return "NO";
        }
    }
    return "YES";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> t;
    while(t --> 0) {
        enter();
        cout << solve() << "\n";
    }
}



