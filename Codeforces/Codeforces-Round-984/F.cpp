
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

int computeXOR(int n) {
    if (n % 4 == 0)
        return n;

    if (n % 4 == 1)
        return 1;

    if (n % 4 == 2)
        return n + 1;

    return 0;
}

// Hàm tính tổng XOR của các số từ l đến r
int xorFromLToR(int l, int r) {
    return computeXOR(r) ^ computeXOR(l - 1);
}

int xorWithCondition(int l, int r, int i, int k) {
    int step = 1 << i;  // Bước nhảy là 2^i

    int first = (l / step) * step + k;
    if (first < l) first += step;  // Đảm bảo first >= l
    if (first > r) return 0;       // Không có số nào thỏa mãn điều kiện

    // Tìm số cuối cùng thỏa mãn trong đoạn [l, r]
    int last = (r / step) * step + k;
    if (last > r) last -= step;  // Đảm bảo last <= r
    cout << first << " " << last << endl;
    // Nếu first và last thỏa mãn điều kiện, tính tổng XOR
    if (first <= last) {
        // Tính số lượng phần tử trong dãy
        int count = (last - first) / step + 1;

        // Nếu số lượng phần tử là chẵn, XOR của dãy là 0
        if (count % 2 == 0) {
            return 0;
        } else {
            // Nếu số lượng phần tử là lẻ, XOR của dãy là XOR từ first đến last
            return xorFromLToR(first, last);
        }
    }

    return 0;
}
void solve() {
    int l, r, k, pw;
    cin >> l >> r >> pw >> k;

    int res = computeXOR(r) ^ computeXOR(l - 1);
    int tmp = xorWithCondition(l, r, pw, k);
    // cout << tmp << "\n";
    cout << (res ^ tmp) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}