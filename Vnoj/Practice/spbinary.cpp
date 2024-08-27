#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int MOD = 1e9;

int getSum(int x, int y) { return (1LL * x + y + MOD) % MOD; }

int getSub(int x, int y) { return (1LL * x - y + MOD) % MOD; }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> f(n + 1, vector<int>(2, 0));
    vector<vector<int>> s(n + 1, vector<int>(2, 0));
    f[1][0] = f[1][1] = 1;
    s[1][0] = s[1][1] = 1;
    // f[i][0]: số dãy bit thỏa mãn đề bài kết thúc tại bit 0
    // f[i][1]: số dãy bit thỏa mãn đề bài kết thúc tại bit 1
    fu(i, 2, k) {
        f[i][0] = getSum(f[i - 1][0], f[i - 1][1]);
        f[i][1] = getSum(f[i - 1][1], f[i - 1][0]);
        s[i][0] = getSum(s[i - 1][0], f[i][0]);
        s[i][1] = getSum(s[i - 1][1], f[i][1]);
    }
    fu(i, k + 1, n) {
        f[i][0] = getSub(s[i - 1][1], s[i - k - 1][1]);
        f[i][1] = getSub(s[i - 1][0], s[i - k - 1][0]);
        s[i][0] = getSum(s[i - 1][0], f[i][0]);
        s[i][1] = getSum(s[i - 1][1], f[i][1]);
    }
    cout << getSum(f[n][0], f[n][1]);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}