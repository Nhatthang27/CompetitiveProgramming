
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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> store;
    store.push_back(x);
    int prev = 0, pos = 1;

    fu(i, 0, m - 1) {
        int u;
        char c;
        cin >> u >> c;
        unordered_map<int, bool> mp;
        int sz = (int)store.size();
        pos = sz;
        if (c == '?') {
            fu(i, prev, sz - 1) {
                int next =
                    (store[i] + u) > n ? u + store[i] - n : (u + store[i]);
                int prc = (store[i] - u) <= 0 ? store[i] - u + n : store[i] - u;
                if (mp.find(next) == mp.end()) {
                    mp[next] = true;
                    store.push_back(next);
                }
                if (mp.find(prc) == mp.end()) {
                    mp[prc] = true;
                    store.push_back(prc);
                }
            }
        }
        if (c == '0') {
            fu(i, prev, sz - 1) {
                int next =
                    (store[i] + u) > n ? u + store[i] - n : (u + store[i]);
                if (mp.find(next) == mp.end()) {
                    mp[next] = true;
                    store.push_back(next);
                }
            }
        }
        if (c != '0' && c != '?') {
            fu(i, prev, sz - 1) {
                int prc = (store[i] - u) <= 0 ? store[i] - u + n : store[i] - u;
                if (mp.find(prc) == mp.end()) {
                    mp[prc] = true;
                    store.push_back(prc);
                }
            }
        }
        prev = sz;
    }
    set<int> s;
    fu(i, pos, (int)store.size() - 1) { s.insert(store[i]); }
    cout << s.size() << "\n";
    for (auto it : s) {
        cout << it << " ";
    }
    cout << "\n";
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}