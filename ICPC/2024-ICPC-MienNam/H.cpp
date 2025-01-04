
#include <bits/stdc++.h>
#define int unsigned long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

int myProduct(int a, int b, int mod) {
    if (a == 0 || b == 0)
        return 0;
    a %= mod;
    b %= mod;
    int res = 0;
    while (b > 0) {
        if (b & 1)
            res = (res + a >= mod ? res + a - mod : res + a);
        a = (a * 2 >= mod ? a * 2 - mod : a * 2);
        b >>= 1;
    }
    return res;
}

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Function to find the modular inverse of a number a mod M
long long mod_inverse(long long a, long long M) {
    long long x, y;
    long long g = extended_gcd(a, M, x, y);
    if (g != 1) {
        // If gcd(a, M) != 1, inverse doesn't exist
        return -1;
    } else {
        // Ensure x is positive
        return (x % M + M) % M;
    }
}

void solve() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    // int res_n2 = myProduct(n2, n2 + 1, m);
    // res_n2 = myProduct(res_n2, n2 * 2 + 1, m);
    // res_n2 = myProduct(res_n2, mod_inverse(6, m), m);

    // n1--;
    // int res_n1 = myProduct(n1, n1 + 1, m);
    // res_n1 = myProduct(res_n1, n1 * 2 + 1, m);
    // res_n1 = myProduct(res_n1, mod_inverse(6, m), m);

    int res_n2 = (n2 * (n2 + 1) % m) * (2 * n2 + 1) % m * mod_inverse(6, m) % m;
    n1--;
    int res_n1 = ((n1 - 1) * n1 % m) * (2 * n1 - 1) % m * mod_inverse(6, m) % m;

    int res = (res_n2 - res_n1 + m) % m;
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