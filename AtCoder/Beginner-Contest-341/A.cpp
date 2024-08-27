#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    ll n;
    cin >> n;
    fu(i, 1, n + 1) {
        if (i != n + 1) {
            cout << "10";
        } else {
            cout << "1";
        }
    }

}
