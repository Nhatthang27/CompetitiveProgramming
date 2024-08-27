
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
int n;
int maxx;

int makeQ(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << "\n";
    cout.flush();
    char in;
    cin >> in;
    return in;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        maxx = 0;
        fu(i, 1, n - 1) {
            if (makeQ(maxx, maxx, i, i) == '<') {
                maxx = max(maxx, 1ll * i);
            }
        }

        int child = -1;
        if (maxx == 0) {
            child = 1;
        } else {
            child = 0;
        }
        fu(i, 1, n) {
            if ((i - 1) != maxx) {
                char in = makeQ(i - 1, maxx, child, maxx);
                if (in == '=') {
                    if (makeQ(i - 1, i - 1, child, child) == '<') {
                        child = i - 1;
                    }
                } else if (in == '>') {
                    child = i - 1;
                }
            }
        }
        cout << "! " << child << " " << maxx << "\n";
        cout.flush();
    }
}