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
    int n;
    cin >> n;
    vector<char> a(n + 1);
    fu(i, 1, n) cin >> a[i];
    vector<int> c2(26, -1);
    fu(i, 0, 25) c2[i] = i;
    int q;
    cin >> q;
    while (q-- > 0) {
        char x, y;
        cin >> x >> y;
        int p = x - 'a';
        int q = y - 'a';
        fu(i, 0, 25) {
            if (c2[i] == p) {
                c2[i] = q;
            }
        }
    }
    fu(i, 1, n) {
        int x = a[i] - 'a';
        if (c2[x] != -1)
            a[i] = c2[x] + 'a';
    }
    fu(i, 1, n) cout << a[i];
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}