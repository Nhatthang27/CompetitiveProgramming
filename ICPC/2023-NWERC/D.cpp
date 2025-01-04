
#include <bits/stdc++.h>
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int DAYS = 7;
const int HOURS = 24;

int agenda[DAYS];
void solve() {
    for (int i = 0; i < DAYS; i++) {
        int mask = 0;
        for (int j = 0; j < HOURS; j++) {
            char x;
            cin >> x;
            if (x == '.')
                mask = mask | (1 << j);
        }
        agenda[i] = mask;
    }
    int d, h;
    cin >> d >> h;

    int x = -1, y = -1;

    vector<int> free;
    for (int mask_hour = 0; mask_hour < (1 << HOURS); mask_hour++) {
        int numHourChoose = __builtin_popcount(mask_hour);

        if (numHourChoose != h)
            continue;
        free.assign(HOURS, 0);
        int numFree = 0;
        for (int i = 0; i < DAYS; i++) {
            int num_free = agenda[i] & mask_hour;
            free[numFree++] = __builtin_popcount(num_free);
        }
        sort(free.begin(), free.begin() + numFree, greater<int>());
        int sum = 0;
        for (int i = 0; i < numFree; i++) {
            sum += free[i];
            if (i + 1 >= d) {
                int total = numHourChoose * (i + 1);
                if (x == -1) {
                    x = sum;
                    y = total;
                } else {
                    int old_v = x * total;
                    int new_v = sum * y;
                    if (new_v > old_v) {
                        x = sum;
                        y = total;
                    }
                }
            }
        }
    }
    double res = 1.0 * x / y;
    cout << fixed << res << setprecision(6);
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}