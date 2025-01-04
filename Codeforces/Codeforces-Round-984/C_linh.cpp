
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void add(int i, int v, vector<int>& fw) {
    for (; i < fw.size(); i += i & -i) {
        fw[i] += v;
    }
}

int get(int i, vector<int>& fw) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += fw[i];
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    vector<int> fw(s.size() + 1);
    for (int i = 0; i < s.size() - 3; ++i) {
        if (s.substr(i, 4) == "1100") {
            add(i + 1, 1, fw);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int i, v;
        cin >> i >> v;
        --i;
        if (s[i] == v + '0') {
            cout << (get(s.size() - 1, fw) ? "YES" : "NO") << '\n';
            continue;
        }
        int res = 0;
        for (int j = max(0ll, i - 3); j <= i; ++j) {
            if (s.substr(j, 4) == "1100") {
                add(j + 1, -1, fw);
            }
        }
        s[i] = v + '0';
        for (int j = max(0ll, i - 3); j <= i; ++j) {
            if (s.substr(j, 4) == "1100") {
                add(j + 1, 1, fw);
            }
        }
        cout << (get(s.size(), fw) ? "YES" : "NO") << '\n';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}