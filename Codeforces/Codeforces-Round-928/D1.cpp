#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(int i = a; i <= b; i++)
#define fd(i,a,b) for(int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int MAX = 1e6 + 7;

void solve() {
    int n, k;
    int cnt = 0;
    cin >> n >> k;
    while(true) {
        int dif = n / 2 + n % 2;
        cnt++;
        if (k <= dif) break;
        n -= dif;
        k -= dif;
    }
    int head = (1 << (cnt - 1));
    cout << head + (head << 1) * (k - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --> 0) {
        solve();
    }
}
