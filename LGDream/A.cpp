
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
    int n, k;
    cin >> n >> k;
    vector<int> one, two;
    int sum = 0;
    fu(i, 1, n) {
        int x;
        cin >> x;
        sum += abs(x);
        if (x > 0) {
            one.push_back(x);
        } else {
            two.push_back(-x);
        }
    }
    if (k == 1) {
        cout << sum * 2 << endl;
        return;
    }

    sort(one.begin(), one.end());
    int id = one.size() - 1;
    int res = 0;
    while (id >= 0) {
        res += one[id] * 2;
        id -= k;
    }

    sort(two.begin(), two.end());
    id = two.size() - 1;
    int res2 = 0;
    while (id >= 0) {
        res2 += two[id] * 2;
        id -= k;
    }
    cout << res + res2 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}