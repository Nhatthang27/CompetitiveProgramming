
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int INF = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - 'a';
    }

    std::vector<int> tail;        // Stores the potential subsequence
    std::vector<int> indices(n);  // Stores indices of elements in the original aay
    std::vector<int> prev(n, -1); // To reconstruct the sequence

    for (int i = 0; i < n; ++i)
    {
        auto it = std::upper_bound(tail.begin(), tail.end(), a[i]); // Find the position to replace or extend
        int index = it - tail.begin();

        if (it == tail.end())
        {
            tail.push_back(a[i]);
        }
        else
        {
            *it = a[i];
        }

        indices[index] = i;
        if (index > 0)
        {
            prev[i] = indices[index - 1];
        }
    }

    // Reconstruct the longest non-descending subsequence
    std::vector<int> result;
    vector<bool> used(n, false);
    for (int i = indices[tail.size() - 1]; i >= 0; i = prev[i])
    {
        used[i] = true;
        result.push_back(a[i]);
    }

    std::reverse(result.begin(), result.end());
    fu(i, 0, n - 1) if (!used[i])
    {
        if (i == 0)
            s[i] = 'a';
        else
            s[i] = s[i - 1];
    }
    cout << n - result.size() << '\n';
    cout << s << '\n';
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