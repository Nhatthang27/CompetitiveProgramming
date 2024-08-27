#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    string s;
    vector<int> cnt(26, 0);
    cin >> s;
    fu(i, 0, s.size() - 1) { cnt[s[i] - 'a']++; }
    fu(i, 0, s.size() - 1) {
        if (cnt[s[i] - 'a'] == 1) {
            cout << i + 1 << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}