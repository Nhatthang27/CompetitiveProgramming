
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
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (k >= sum) {
        cout << n << "\n";
        return;
    }
    int le = k / 2;
    int ri = k / 2;
    int du = k % 2;
    int ans = 0;
    int l = 1;
    int r = n;
    while (l <= n && le > 0) {
        int tmp = min(le, a[l]);
        le -= tmp;
        a[l] -= tmp;
        l++;
    }
    while (1 <= r && ri > 0) {
        int tmp = min(ri, a[r]);
        ri -= tmp;
        a[r] -= tmp;
        r--;
    }
    if (du) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) {
                a[i]--;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += (a[i] == 0);
        //        cout<<a[i]<<" ";
    }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}