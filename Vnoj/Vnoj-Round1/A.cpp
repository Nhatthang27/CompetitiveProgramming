#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;
const ll INF = 1e18;

ll n, a[MAX];

void enter() {
    cin >> n;
    fu(i, 1, n) {
        cin >> a[i];
    }
}

void solve() {
    bool flag = false;
    ll res = -INF;
    fu(j, 2, n - 1) {
        bool one = false;
        ll oneVal = -INF;
        fu(i, 1, j - 1) {
            if (a[i] < a[j]) {
                one = true;
                oneVal = max(oneVal, a[i]);
            }
        }
        bool two = false;
        ll twoVal = -INF;
        fu(k, j + 1, n) {
            if (a[k] > a[j]) {
                two = true;
                twoVal = max(twoVal, a[k]);
            }
        }
        if (one == true && two == true) {
            flag = true;
            res = max(res, oneVal + a[j] + twoVal);
        }
    }
    if (flag == false) {
        cout << -1;
    } else {
        cout << res;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    solve();
}


