#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = a; i <= b; i++)
#define fd(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 2e5 + 7;

ll a[MAX];
ll n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> n;
    fu(i, 1, n) {
        cin >> a[i];
    }
    ll mi = 0;
    ll sum = 0;
    fu(i, 1, n) {
        sum += a[i];
        if (sum < 0) {
            mi = min(mi, sum);
        }
    }
    cout << sum + mi * (-1);
}

