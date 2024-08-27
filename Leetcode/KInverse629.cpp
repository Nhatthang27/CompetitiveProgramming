#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int maxN = 5;
    fu(n, 1, maxN) {
        vector<int> a(n + 1, 0);
        cout << "n = " << n << "\n";
        fu(i, 1, n) a[i] = i;
        do {
            int cnt = 0;
            fu(i, 2, n) {
                fu(j, 1, i - 1) {
                    if (a[j] > a[i]) cnt++;
                }
            }
            fu(i, 1, n) {
                cout << a[i] << " ";
            }
            cout << "num Inverse = " << cnt << "\n";
        } while(next_permutation(a.begin() + 1, a.begin() + n + 1));
        cout << "\n";
    }
}
