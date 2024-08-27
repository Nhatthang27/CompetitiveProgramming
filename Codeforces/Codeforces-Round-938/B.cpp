
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
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> tmp(n * n + 1);
    map<int, int> mp;
    fu(i, 1, n * n) cin >> tmp[i], mp[tmp[i]]++;
    sort(tmp.begin() + 1, tmp.end());
    int mi = tmp[1];

    vector<vector<int>> a(n + 1, vector<int>(n + 1));

    a[1][1] = mi;
    fu(j, 2, n) {
        if (mp[a[1][j - 1] + d] == 0) {
            cout << "NO\n";
            return;
        }
        mp[a[1][j - 1] + d]--;
        a[1][j] = a[1][j - 1] + d;
    }

    fu(i, 2, n) {
        if (mp[a[i - 1][1] + c] == 0) {
            cout << "NO\n";
            return;
        }
        mp[a[i - 1][1] + c]--;
        a[i][1] = a[i - 1][1] + c;
    }
    fu(i, 2, n) {
        fu(j, 2, n) {
            int x = a[i - 1][j] + c;
            int y = a[i][j - 1] + d;
            if (x != y || mp[x] == 0) {
                cout << "NO\n";
                return;
            }
            mp[x]--;
            a[i][j] = x;
        }
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