#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 1e5 + 7;
ll n, q, s, d, num;
ll sq;
vector<ll> a;
vector<vector<ll> > f;
vector<vector<ll> > super;

void prepare() {
    sq = sqrt(n) + 1;
    f.assign(sq + 1, vector<ll>(n + 1, 0));
    super.assign(sq + 1, vector<ll>(n + 1, 0));
    fu(dis, 1, sq) {
        for(ll i = 1; i <= n; i++) {
            if (i <= dis) {
                super[dis][i] = f[dis][i] = a[i];
            } else {
                f[dis][i] = f[dis][i - dis] + a[i];
                super[dis][i] = super[dis][i - dis] + a[i] * (i / dis + (i % dis != 0));
            }
        }
    }
}

void solve() {
    while(q --> 0) {
        cin >> s >> d >> num;
        ll res = 0;
        if (d >= sq) {
            for(ll i = s, cnt = 1; cnt <= num; cnt++, i += d) {
                res += a[i] * cnt;
            }
        } else {
            ll last = s + d * (num - 1);
            res = super[d][last] - (s > d ? super[d][s - d] : 0);
            res -= (f[d][last] - (s > d ? f[d][s - d] : 0)) * (s / d + (s % d != 0) - 1);
        }
        cout << res << " ";
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie();
    ll t;
    cin >> t;
    while(t --> 0) {
        cin >> n >> q;
        a.resize(n + 7);
        fu(i, 1, n) cin >> a[i];
        prepare();
        solve();
    }
}
