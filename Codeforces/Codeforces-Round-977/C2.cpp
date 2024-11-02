
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1, 0), b(m + 1, 0);
    fu(i, 1, n)
    {
        cin >> a[i];
    }
    fu(i, 1, m)
    {
        cin >> b[i];
    }
    map<int, bool> mp;

    if (a[1] != b[1])
    {
        cout << "TIDAK\n";
    }
    else
    {
        int front = 1;
        int x = a[front];
        bool ok = true;
        fu(i, 2, m)
        {
            if (b[i] != x)
            {
                if (mp[b[i]])
                {
                    mp[x] = true;
                    mp[b[i]] = false;
                    x = b[i];
                }
                else if (front + 1 <= n && b[i] == a[front + 1])
                {
                    mp[x] = true;
                    front++;
                    x = a[front];
                }
                else
                {
                    cout << "TIDAK\n";
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
            cout << "YA\n";
    }
    fu(i, 1, q)
    {
        int si, ti;
        cin >> si >> ti;

        b[si] = ti;

        if (a[1] != b[1])
        {
            cout << "TIDAK\n";
        }
        else
        {
            int front = 1;
            int x = a[front];
            bool ok = true;

            fu(i, 2, m)
            {
                if (b[i] != x)
                {
                    if (mp[b[i]])
                    {
                        mp[x] = true;
                        mp[b[i]] = false;
                        x = b[i];
                    }
                    else if (front + 1 <= n && b[i] == a[front + 1])
                    {
                        mp[x] = true;
                        front++;
                        x = a[front];
                    }
                    else
                    {
                        ok = false;
                        cout << "TIDAK\n";
                        break;
                    }
                }
            }
            if (ok)
                cout << "YA\n";
        }
    }
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