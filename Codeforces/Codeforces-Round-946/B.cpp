
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
    string s;
    int n;
    cin >> n;
    cin >> s;
    set<char> st;
    for (char c : s) {
        st.insert(c);
    }
    vector<int> dt;
    for (char c : st) {
        dt.push_back(c);
    }
    vector<int> mp(26, -1);
    int l = 0;
    int r = dt.size() - 1;
    while (l < r) {
        int a = dt[l] - 'a';
        int b = dt[r] - 'a';
        mp[a] = b;
        mp[b] = a;
        l++;
        r--;
    }
    for (int i = 0; i < n; i++) {
        if (mp[s[i] - 'a'] != -1) {
            s[i] = mp[s[i] - 'a'] + 'a';
        }
    }
    cout << s << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}