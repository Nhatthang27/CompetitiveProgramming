#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b)  for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 1e5 + 7;

vector<ll> a, aft, bef;
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    ll t;
    cin >> t;
    while (t --> 0) {
        ll n;
        cin >> n;
        a.assign(n + 7, 0);
        aft.assign(n + 7, 0);
        bef.assign(n + 7, 0);
        fu(i, 1, n) {
            cin >> a[i];
        }
        aft[1] = 1;
        aft[n] = 0;
        fu(i, 2, n - 1) {
            if (a[i + 1] - a[i] < a[i] - a[i - 1]) {
                aft[i] = 1;
            } else {
                aft[i] = a[i + 1] - a[i];
            }
        }
        bef[1] = 0;
        bef[n] = 1;
        fd(i, n - 1, 2) {
            if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
                bef[i] = 1;
            } else {
                bef[i] = a[i] - a[i - 1];
            }
        }
        fu(i, 2, n) {
            aft[i] += aft[i - 1];
        }
        fd(i, n - 1, 1) {
            bef[i] += bef[i + 1];
        }
//        fu(i, 1, n) {
//            cout << aft[i] << " ";
//        }
//        cout << "\n";
//        fu(i, 1, n) {
//            cout << bef[i] << " ";
//        }
//        cout << "\n";
        ll q;
        cin >> q;
        while(q --> 0) {
            ll l, r;
            cin >> l >> r;
            if (l > r) {
                cout << bef[r + 1] - bef[l + 1] << "\n";
            } else {
                cout << aft[r - 1] - aft[l - 1] << "\n";
            }
        }
    }
}

