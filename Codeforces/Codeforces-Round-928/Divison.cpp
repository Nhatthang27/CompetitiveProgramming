#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
const int MASK = (1 << 31) - 1;
map<int, int> mp;
int n;

void solve() {
    int nGroup = 0;
    mp.clear();
    cin >> n;
    fu(i, 1, n) {
        int x;
        cin >> x;
        if (mp[x ^ MASK] > 0) {
            mp[x ^ MASK]--;
            nGroup++;
        } else {
            mp[x]++;
        }
    }
    cout << (n - nGroup * 2) + nGroup << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
