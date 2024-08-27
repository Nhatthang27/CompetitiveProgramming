
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
    int n, nL, nW;
    cin >> n >> nL >> nW;
    vector<char> land(n + 1);
    fu(i, 1, n) cin >> land[i];

    int endWater = 0;
    fd(i, n, 1) {
        if (land[i] != 'W') {
            endWater = n - i;
            break;
        }
    }
    if (endWater > nL && endWater > nW) {
        cout << "NO\n";
        return;
    }
    int i = n - endWater;
    while (i >= 1) {
        int cnt = 0;
        while (i >= 1 && land[i] != 'L') {
            cnt++;
            i--;
        }
        if (cnt >= nL) {
            cout << "NO\n";
            return;
        }
        i--;
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}