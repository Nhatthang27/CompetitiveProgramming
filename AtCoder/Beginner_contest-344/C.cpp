
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    int na, nb, nc, nx;
    cin >> na;
    vector<int> a(na + 1);
    fu(i, 1, na) cin >> a[i];
    cin >> nb;
    vector<int> b(nb + 1);
    fu(i, 1, nb) cin >> b[i];
    cin >> nc;
    vector<int> c(nc + 1);
    fu(i, 1, nc) cin >> c[i];

    map<int, bool> m;
    fu(i, 1, na) {
        fu(j, 1, nb) {
            fu(k, 1, nc) { m[a[i] + b[j] + c[k]] = true; }
        }
    }
    cin >> nx;
    fu(i, 1, nx) {
        int x;
        cin >> x;
        if (m[x]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}