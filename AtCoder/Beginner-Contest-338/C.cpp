#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 1e6 + 7;

ll q[20], a[20], b[20], tmp[20];
ll n;

void enter() {
    cin >> n;
    fu(i, 1, n) cin >> q[i];
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) cin >> b[i];
}

void solve() {
    ll res = 0;
    bool flag = true;
    ll demA = 0;
    while(true) {
        fu(i, 1, n) {
            tmp[i] = q[i] - demA * a[i];
            if (tmp[i] < 0) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
        ll demB = 1000000000000000;
        fu(i, 1, n) {
            if (b[i] == 0) continue;
            demB = min(demB, tmp[i] / b[i]);
        }
        res = max(res, demA + demB);
        demA++;
    }
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    solve();
}



