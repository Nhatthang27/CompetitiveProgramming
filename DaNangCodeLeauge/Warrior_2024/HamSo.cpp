#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

vector<vector<ll>> multiply(const vector<vector<ll>> &A, const vector<vector<ll>> &B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll p) {
    int n = A.size();
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
        result[i][i] = 1;
    while (p) {
        if (p % 2)
            result = multiply(result, A);
        A = multiply(A, A);
        p /= 2;
    }
    return result;
}

ll compute_F_n(ll n, ll a, ll b, ll c, ll d) {
    if (n == 0) return b % MOD;
    if (n == 1) return a % MOD;

    vector<vector<ll>> A = {
        {0, 2, 0, 0},
        {1, 3, 0, 0},
        {0, 3, 0, 2},
        {0, 2, 1, 1}};

    vector<vector<ll>> An = power(A, n - 1);

    vector<ll> v = {b, a, d, c};

    ll result = 0;
    for (int i = 0; i < 4; ++i)
        result = (result + An[i][1] * v[i]) % MOD;
    return result;
}

int main() {
    ll a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    ll result = compute_F_n(n, a, b, c, d);
    cout << result << endl;

    return 0;
}
