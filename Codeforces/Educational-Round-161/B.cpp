#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b)  for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 3e5 + 7;

vector<ll> cnt, sum;

ll cal3(ll x) {
    return x * (x - 1) * (x - 2) / 6;
}

ll cal2(ll x) {
    return x * (x - 1) / 2;
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    ll t;
    cin >> t;
    while (t --> 0) {
        ll n;
        cin >> n;
        vector<ll> v;
        cnt.assign(n + 7, 0);
        sum.assign(n + 7, 0);
        fu(i, 1, n) {
            ll x;
            cin >> x;
            if (cnt[x] == 0) {
                v.push_back(x);
            }
            cnt[x]++;
        }
        sum[0] = cnt[0];
        fu(i, 1, n) {
            sum[i] = sum[i - 1] + cnt[i];
        }
        sort(v.begin(), v.end());
        ll res = 0;
        for(ll x : v) {
//                cout << x << " " << cnt[x] << "\n";
            if (cnt[x] >= 2 && x > 0) {
                res += cal2(cnt[x]) * sum[x - 1];
            }
            if (cnt[x] >= 3) {
                res += cal3(cnt[x]);
            }
        }
//        cout << "=--------------";
        cout << res << "\n";
    }
}
