#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MASK(i) (1LL << i)

using namespace std;
const ll MAX = 1e6 + 7;
const ll INF = 1e18;
const ll MBIT = 20;
ll n, t, a[MAX];
ll cnt[20];

bool getBit(ll mask, ll i) {
    return (mask >> i) & 1;
}



void enter() {
    cin >> n;
    fu(i, 1, n) {
        cin >> a[i];
        fd(k, MBIT, 0) {
//            cout << getBit(a[i], k) ? 1 : 0;
            if (getBit(a[i], k)) cnt[k]++;
        }
//        cout << "\n";
    }
//    fd(k, MBIT, 0) {
//        cout << cnt[k];
//    }
//    cout << "=================\n";
}

void solve() {
    ll res = 0;
    fu(i, 1, n - 1) {
        fu(j, i + 1, n) {
            bool flag = true;
            fd(k, MBIT, 0) {
                ll cc = getBit(a[i], k) + getBit(a[j], k);
//                cout << i << " " << j << " " << cc << "\n";
                if (cc == 0 && cnt[k] > 0) {
                    flag = false;
                    break;
                }
                if (cc > 0 && cnt[k] == cc) {
                    flag = false;
                    break;
                }
            }
            if (flag) res++;
        }
    }
    cout << res * 2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    solve();
}






