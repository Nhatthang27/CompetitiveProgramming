
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
    vector<pii> a(n + 1);

    fu(i, 1, n) {
        cin >> a[i].ff >> a[i].ss;
    }
    sort(a.begin() + 1, a.end());

    function<bool(int)> isGood = [&](int x) {
        vector<bool> deleted(n + 1, false);
        int highest = a[1].ss;
        int rightmost = a[1].ff + x;
        fu(i, 1, n) {
            if (a[i].first > rightmost) {
                break;
            }
            if (a[i].second > highest) {
                highest = a[i].second;
            }
        }
        fu(i, 1, n) {
            if (a[i].first > rightmost) {
                break;
            }
            if (a[i].second < highest - x) {
                deleted[i] = true;
            }
        }

        int leftmost = LONG_LONG_MAX;
        fu(i, 1, n) {
            if (!deleted[i]) {
                leftmost = min(leftmost, a[i].first);
            }
        }
        if (leftmost == LONG_LONG_MAX) {
            return true;
        }
        rightmost = leftmost + x;
        highest = LONG_LONG_MIN;
        fu(i, 1, n) {
            if (deleted[i]) continue;
            if (a[i].first > rightmost) {
                break;
            }
            if (a[i].second > highest) {
                highest = a[i].second;
            }
        }
        if (highest == LONG_LONG_MIN) {
            return true;
        }
        fu(i, 1, n) {
            if (deleted[i]) continue;
            if (a[i].first > rightmost) {
                break;
            }
            if (a[i].second < highest - x) {
                deleted[i] = true;
            }
        }

        leftmost = LONG_LONG_MAX;
        fu(i, 1, n) {
            if (!deleted[i]) {
                leftmost = min(leftmost, a[i].first);
            }
        }
        if (leftmost == LONG_LONG_MAX) {
            return true;
        }
        rightmost = leftmost + x;
        highest = LONG_LONG_MIN;
        fu(i, 1, n) {
            if (deleted[i]) continue;
            if (a[i].first > rightmost) {
                break;
            }
            if (a[i].second > highest) {
                highest = a[i].second;
            }
        }
        if (highest == LONG_LONG_MIN) {
            return true;
        }
        fu(i, 1, n) {
            if (deleted[i]) continue;
            if (a[i].first > rightmost) {
                break;
            }
            if (a[i].second < highest - x) {
                return false;
            }
        }

        fu(i, 1, n) {
            if (!deleted[i]) return false;
        }
        return true;
    };

    int l = 1, r = 1e18;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (isGood(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}