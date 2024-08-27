#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const ll MAX = 2e5 + 7;

ll n, a[MAX];
ll s[MAX], t[MAX];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    ll n;
    cin >> n;
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n - 1) {
        cin >> s[i] >> t[i];
    }
    fu(i, 1, n - 1) {
        a[i + 1] += a[i] / s[i] * t[i];
    }
    cout << a[n];
}

