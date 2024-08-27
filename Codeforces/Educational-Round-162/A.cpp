#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    int l1 = 0;
    fu(i, 1, n) {
        cin >> a[i];
        if (l1 == 0 && a[i] == 1) {
            l1 = i;
        }
    }
    ll res = 0;
    fd(i, n, 1) {
        if (a[i] == 1) {
            fd(j, i - 1, 1) {
                if (a[j] == 0) {
                    if (j < l1) {
                        cout << res << "\n";
                        return;
                    }
                    swap(a[i], a[j]);
                    res++;
                    break;
                }
            }
        }
    }
    cout << res << "\n";
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}