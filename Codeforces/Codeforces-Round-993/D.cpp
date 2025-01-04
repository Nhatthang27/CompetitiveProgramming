
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> res(n + 1);
    queue<int> q;

    int ma = 1;
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[a[i]] < ma)
        {
            res[i] = a[i];
            cnt[a[i]]++;

            while (cnt[a[i]] < ma)
            {
                int id = q.front();
                q.pop();
                res[id] = a[i];
                cnt[a[i]]++;
            }
        }
        else
        {
            q.push(i);
        }
    }
    queue<int> q2;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
            q2.push(i);
    }

    for (int i = 1; i <= n; i++)
        if (res[i] == 0)
        {
            cout << q2.front() << " ";
            q2.pop();
        }
        else
            cout << res[i] << " ";
    cout << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}