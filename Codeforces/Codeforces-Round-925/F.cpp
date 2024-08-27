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

ll n, k;
ll t;
vector<vector<ll>> a;

void enter() {
    cin >> n >> k;
    a.assign(k + 1, vector<ll>(n + 1, 0));
    fu(i, 1, k)
    fu(j, 1, n)
     cin >> a[i][j];
}

void solve() {
    vector<ll> order(n + 1, 0);
    if (k == 1 || n <= 2) {
        cout << "YES\n";
        return;
    } else {
        fu(i, 2, n) {
            order[a[1][i]] = i;
        }
        fu(i, 2, n) {
            if (order[a[2][i]] == 0){
                if (i + 1 <= n) {
                    order[a[2][i]] = order[a[2][i + 1]] - 1;
                    if (order[a[2][i]] == 0) order[a[2][i]] = 1;
                } else {
                    order[a[2][i]] = order[a[2][i - 1]] + 1;
                    if (order[a[2][i]] == n + 1) order[a[2][i]] = n;
                }

                fu(j, i + 1, n) {
                    order[a[2][j]] = order[a[2][j - 1]] + 1;
                }
                break;
            }
        }
        fu(i, 2, n) {
            fu(j, 2, n) {
                if (order[a[i][j]] != order[a[i][j - 1]] + 1) {
                    cout << "NO\n";
                    return;
                }
            }
        }
        cout << "YES\n";
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






