#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MASK(i) (1LL << i)

using namespace std;
const ll MAX = 1e7;
const ll INF = 1e18;

ll n;
ll sum[MAX + 7];
bool isPrime[MAX+ 7];

void solve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(ll x = 2; x <= MAX; x++) {
        for(ll y = 2; x * y <= MAX; y++) {
            isPrime[x * y] = false;
        }
    }
    ll cnt = 0;
    fu(x, 2, MAX) {
        if (isPrime[x]) {
            ++cnt;
            sum[cnt] = x + sum[cnt - 1];
        }
    }

    fd(res, 605000, 1) {
        fu(i, 1, 605000 - res + 1) {
            ll j = i + res - 1;
            ll tmp = sum[j] - sum[i - 1];
            if (tmp % res == 0 && isPrime[tmp / res]) {
                cout << res << "\n";
                fu(k, i, j) {
                    cout << sum[k] - sum[k - 1] << " ";
                }
                return;
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    solve();
}




