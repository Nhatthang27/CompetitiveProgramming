
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(m + 1);
    map<int, int> cnt, cntTmp;
    vector<int> save;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }
    int ans = 0, dem = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt[a[i]] == 0) continue;
        //        if(cntTmp[a[i]]==cnt[b[i]]) continue;
        // cout<<a[i]<<" ";
        cntTmp[a[i]]++;
        if (cntTmp[a[i]] <= cnt[a[i]]) dem++;
        //        dem++;
    }
    //    cout<<dem<<"\n";
    if (dem >= k) ans++;
    int l = 1;
    for (int i = m + 1; i <= n; i++) {
        if (cnt[a[i]] != 0) {
            cntTmp[a[i]]++;
            if (cntTmp[a[i]] <= cnt[a[i]]) dem++;
        }
        if (cnt[a[l]] != 0) {
            cntTmp[a[l]]--;
            if (cntTmp[a[l]] < cnt[a[l]]) dem--;
        }
        l++;
        if (dem >= k) {
            //            cout<<l<<" "<<i<<" "<<dem<<"aaa\n";;
            ans++;
        }
    }
    //    cout<<"\n";
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