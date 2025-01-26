
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string res = "YES";
    for(int i = 0; i < n - 1; i++) {
        if(a[i + 1] < a[i]) {
            res = "NO";
            break;
        }
        a[i + 1] -= min(a[i + 1], a[i]);
    }
    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}