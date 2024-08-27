#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0);
    vector<ll> x(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    fu(i, 1, n) cin >> a[i];
    fu(i, 1, n) {
        cin >> x[i];
        q.push(make_pair(abs(x[i]), a[i]));
    }

    ll step = 0;
    ll bul = 0;
    while (!q.empty()) {
        ll pos = q.top().ff - step;
        ll heal = q.top().ss;
        q.pop();
        if (heal - bul > k * pos) {
            cout << "NO\n";
            return;
        } else {
            ll thua = heal - bul;
            ll conti = thua / k + (thua % k != 0);
            bul = k * conti - thua;
            step += conti;
        }
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}