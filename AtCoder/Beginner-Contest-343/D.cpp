
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
    int n, t;
    cin >> n >> t;
    map<int, int> mp;
    vector<int> a(n + 1, 0);
    int numDif = 1;
    mp[0] = n;
    fu(i, 1, t) {
        int id, p;
        cin >> id >> p;

        if (mp[a[id]] == 1) {
            numDif--;
        }
        mp[a[id]]--;
        a[id] += p;
        if (mp[a[id]] == 0) {
            numDif++;
            mp[a[id]] = 1;
        } else {
            mp[a[id]]++;
        }

        cout << numDif << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}