#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(4);
        for (auto &c : a) cin >> c;

        vector<int> even(4), odd(4);
        for (int i = 0; i < 4; ++i) {
            even[i] = a[i] / 2 + 1;
            odd[i] = (a[i] & 1);
        }
        even[3]--;

        int res = even[0] + even[1] + even[2] - 3;

        cout << res + even[3] + (odd[0] && odd[1] && odd[2]) << '\n';
    }
}