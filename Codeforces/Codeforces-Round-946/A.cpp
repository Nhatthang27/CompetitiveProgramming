#include <iostream>
#include <map>
#include <vector>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<tuple<int, int, int>, int> cnt;
    int ans = 0;

    for (int i = 0; i < n - 2; ++i) {
        tuple<int, int, int> triplet = make_tuple(a[i], a[i + 1], a[i + 2]);
        tuple<int, int, int> mist[3] = {
            make_tuple(0, a[i + 1], a[i + 2]),
            make_tuple(a[i], 0, a[i + 2]),
            make_tuple(a[i], a[i + 1], 0)};

        for (int j = 0; j < 3; ++j) {
            ans += cnt[mist[j]] - cnt[triplet];
            cnt[mist[j]] = cnt[mist[j]] + 1;
        }
        cnt[triplet] = cnt[triplet] + 1;
    }
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
