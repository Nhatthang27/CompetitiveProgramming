
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

const int MAX = 3e5 + 7;
int a[MAX], b[MAX];
int n, m;
vector<int> store;

void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    int first_element = a[1];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    store.clear();
    for (int i = 1; i <= m; ++i)
    {
        if (b[i] > first_element)
        {
            int pos = lower_bound(a + 1, a + n + 1, b[i]) - a;
            store.push_back(n - pos + 1);
        }
        else
        {
            store.push_back(0);
        }
    }
    sort(store.begin(), store.end());

    for (int i = 1; i <= m; ++i)
    {
        int sum = 0;
        for (int j = 1; j + i - 1 <= m; j += i)
        {
            sum += store[j + i - 1 - 1] + 1;
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}