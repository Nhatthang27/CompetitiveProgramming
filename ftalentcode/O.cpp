
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
    int n, k, s;
    cin >> n >> k >> s;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
    fu(i, 1, n)
    {
        fu(j, 1, n)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> max_value(n + 1, vector<int>(n + 1, LONG_LONG_MIN));
    // max_value[i][j] is the maximum value of mat[i][j] mat[i + 1][j] mat[i + 2][j] ... mat[i + k - 1][j] with k elements

    // Precompute the maximum values for each column in a sliding window of size k
    vector<vector<int>> col_max(n + 1, vector<int>(n + 1, LONG_LONG_MIN));
    fu(j, 1, n)
    {
        deque<int> dq;
        fu(i, 1, n)
        {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && mat[dq.back()][j] <= mat[i][j])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k)
                col_max[i - k + 1][j] = mat[dq.front()][j];
        }
    }

    // Compute the maximum values for each row in a sliding window of size k
    fu(i, 1, n - k + 1)
    {
        deque<int> dq;
        fu(j, 1, n)
        {
            while (!dq.empty() && dq.front() <= j - k)
                dq.pop_front();
            while (!dq.empty() && col_max[i][dq.back()] <= col_max[i][j])
                dq.pop_back();
            dq.push_back(j);
            if (j >= k)
                max_value[i][j - k + 1] = col_max[i][dq.front()];
        }
    }

    for (int i = 1; i <= n - k + 1; i += s)
    {
        for (int j = 1; j <= n - k + 1; j += s)
        {
            cout << max_value[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}