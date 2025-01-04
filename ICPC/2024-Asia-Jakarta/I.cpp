
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct FenwickTree {
    int n;
    vector<int> fw;

    FenwickTree(int _n) {
        n = _n + 7;
        fw.assign(n + 7, 0);
    }

    void add(int pos, int val) {
        for (int i = pos; i < n; i += i & -i) {
            fw[i] += val;
        }
    }

    int get(int pos) {
        int sum = 0;
        for (int i = pos; i > 0; i -= i & -i) {
            sum += fw[i];
        }
        return sum;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int res = 0;
    int numUnique = (int)cnt.size();

    unordered_map<int, int> last;
    FenwickTree fw(n);
    for (int i = 1; i <= n; i++) {
        int last_i = last[a[i]];
        // for (auto& ele : last) {
        //     int val = ele.first;
        //     int j = ele.second;
        //     if (j > last_i && j < i) {
        //         res++;
        //     }
        // }
        res += fw.get(i) - fw.get(last_i);
        if (last[a[i]] != 0) fw.add(last[a[i]], -1);
        fw.add(i, 1);
        last[a[i]] = i;
    }
    res += numUnique * (m - numUnique);
    res += numUnique * (numUnique - 1) / 2;
    cout << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}