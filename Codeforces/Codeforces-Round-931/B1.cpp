
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve {
    vector<int> coins = {1, 3, 6, 10, 15};
    sort(coins.rbegin(), coins.rend());

    for (int i = 0; i < t; ++i) {
        int n = test_cases[i];
        int count = 0;
        for (int coin : coins) {
            while (n >= coin) {
                n -= coin;
                ++count;
            }
        }
        results[i] = count;
    }
}

int32_t main() { solve(); }