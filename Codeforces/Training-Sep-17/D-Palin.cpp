
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
    int n, k;
    cin >> n >> k;
    vector<int> cnt(26, 0);
    string s;
    cin >> s;
    fu(i, 0, n - 1) {
        cnt[s[i] - 'a']++;
    }

    auto count = [&](int x, vector<int> cnt) {
        int res = 0;
        int odd = 0;
        fu(i, 0, 25) {
            res += cnt[i] / x;
            cnt[i] %= x;
            odd += cnt[i] % 2;
            cnt[i] -= cnt[i] % 2;
        }
        vector<int> cnt2;
        fu(i, 0, 25) {
            if (cnt[i] > 0) {
                cnt2.push_back(cnt[i]);
            }
        }
        sort(cnt2.begin(), cnt2.end());
        int last = cnt2.size() - 1;
        for (int i = 0; i <= last; i++) {
            // fu(j, 0, cnt2.size() - 1) {
            //     cout << cnt2[j] << " ";
            // }
            // cout << endl;
            int sum = 0;
            while (i <= last && sum < (x - x % 2)) {
                sum += cnt2[i];
                i++;
            }
            if (sum >= (x - x % 2)) {
                res++;
                i--;
                cnt2[i] = sum - (x - x % 2);
                if (x % 2 == 1) {
                    if (odd > 0) {
                        odd--;
                    } else {
                        while (last >= i && cnt2[last] == 0) {
                            last--;
                        }
                        if (last < i) break;
                        cnt2[last]--;
                    }
                }
                if (cnt2[i] > 0) i--;
            } else {
                break;
            }
        }
        return res;
    };
    int l = 1, r = n;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (count(mid, cnt) >= k) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
    // cout << count(3, cnt) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
