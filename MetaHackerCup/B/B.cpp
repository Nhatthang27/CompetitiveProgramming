
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

const int N = 10000000;
vector<int> res(N + 7, 0);
vector<bool> isPrime(N + 7, true), correct(N + 7, false);

void precompute()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    correct[2] = correct[3] = true;
    for (int i = 4; i <= N; i++)
    {
        if (isPrime[i] && isPrime[i + 2])
        {
            correct[i] = true;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        res[i] = res[i - 1] + correct[i];
    }
}

void solve()
{
    int n;
    cin >> n;
    if (n <= 4)
    {
        cout << 0 << endl;
        return;
    }
    cout << res[n - 2] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    precompute();
    int t;
    cin >> t;
    fu(i, 1, t)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}