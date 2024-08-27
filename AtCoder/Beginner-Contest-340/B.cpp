#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    ll q, t, x;
    cin >> q;
    vector<ll> a;
    while(q-->0) {
        cin >> t;
        cin >> x;
        if (t == 1) {
            a.push_back(x);
        } else {
            cout << a[a.size() - x] << "\n";
        }
    }
}

