
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
    vector<int> a(n);

    multiset<int> s;
    fu(i, 0, n - 1)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    while (s.size() > 1)
    {
        int x = *s.begin();
        s.erase(s.begin());
        int y = *s.begin();
        s.erase(s.begin());
        s.insert((x + y) / 2);
    }
    cout << *s.begin() << "\n";
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