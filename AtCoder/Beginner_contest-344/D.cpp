
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
    string sample;
    cin >> sample;
    int n;
    cin >> n;
    vector<vector<string>> bag(n + 1);
    fu(i, 1, n) {
        int k;
        cin >> k;
        while (k-- > 0) {
            string s;
            cin >> s;
            bag[i].push_back(s);
        }
    }
    int res = LONG_LONG_MAX;

    function<void(int, int, string)> backtrack = [&](int row, int cost,
                                                     string cur) {
        if (cur == "") {
            res = min(res, cost);
            return;
        }
        if (row > n || cost >= res)
            return;
        for (auto s : bag[row]) {
            int len = s.size();
            string head = (len == cur.size() ? cur : cur.substr(0, len));
            if (head == s) {
                string newCur = cur.substr(len);
                backtrack(row + 1, cost + 1, newCur);
            }
        }
        backtrack(row + 1, cost, cur);
    };
    backtrack(1, 0, sample);
    cout << (res == LONG_LONG_MAX ? -1 : res);
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}