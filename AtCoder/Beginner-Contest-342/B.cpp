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
    vector<int> a(n + 1);
    fu(i, 1, n) {
        int x;
        cin >> x;
        a[x] = i;
    }
    int q;
    cin >> q;
    while (q-- > 0) {
        int x, y;
        cin >> x >> y;
        if (a[x] < a[y])
            cout << x << "\n";
        else
            cout << y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}