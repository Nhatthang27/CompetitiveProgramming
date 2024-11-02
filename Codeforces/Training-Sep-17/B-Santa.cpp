
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
    int n;
    cin >> n;
    vector<int> a;

    int sum = 0;
    int cur = 1;
    while (true) {
        a.push_back(cur);
        sum += cur;
        // cout << "-> " << sum << "\n";
        if (sum == n) {
            cout << a.size() << endl;
            for (int i = 0; i < a.size(); i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            return;
        }
        if (sum > n) {
            sum -= cur;
            a.pop_back();
            int last = n - sum;
            // cout << " ! " << sum << " " << last << " " << a.back() << endl;
            while (!a.empty() && last <= a.back()) {
                sum -= a.back();
                a.pop_back();
                last = n - sum;
                // cout << last << endl;
            }
            a.push_back(last);
            cout << a.size() << endl;
            for (int i = 0; i < a.size(); i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            return;
        }
        cur++;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}