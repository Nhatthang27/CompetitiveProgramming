#include <bits/stdc++.h>
#include <utility>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 1e6 + 7;

ll n, m;
ll t;
ll a[MAX];

ll cntLastZero(ll x) {
    ll cnt = 0;
    while(x % 10 == 0) {
        x /= 10;
        cnt++;
    }
    return cnt;
}

ll po10(ll x) {
    ll res = 1;
    ll cc = cntLastZero(x);
    fu(i, 1, cc) res *= 10;
    return res;
}

bool cmp(ll x, ll y) {
    return cntLastZero(x) > cntLastZero(y);
}

void enter() {
    cin >> n >> m;
    fu(i, 1, n) cin >> a[i];

}

void solve() {
    sort(a + 1, a + n + 1, cmp);
    ll res = 0;
    bool flag = false;
    fu(i, 1, n) {
        if (!flag && cntLastZero(a[i]) != 0) {
            a[i] /= po10(a[i]);
        }
        flag = !flag;
    }
    fu(i, 1, n) {
        res += to_string(a[i]).size();
    }
    if (res > m) {
        cout << "Sasha\n";
    } else {
        cout << "Anna\n";
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






