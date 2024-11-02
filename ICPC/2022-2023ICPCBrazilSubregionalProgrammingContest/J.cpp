
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
    vector<int> card;
    fu(i, 1, 9) fu(j, 1, 4) card.push_back(i);

    fu(i, 1, 12) card.push_back(10);

    int n;
    cin >> n;

    int mary = 0, john = 0;
    fu(i, 1, 2)
    {
        int x;
        cin >> x;
        x = min(x, (int)10);
        card.erase(find(card.begin(), card.end(), x));
        john += x;
    }

    fu(i, 1, 2)
    {
        int x;
        cin >> x;
        x = min(x, (int)10);
        card.erase(find(card.begin(), card.end(), x));
        mary += x;
    }

    fu(i, 1, n)
    {
        int x;
        cin >> x;
        x = min(x, (int)10);

        card.erase(find(card.begin(), card.end(), x));
        mary += x;
        john += x;
    }

    sort(card.begin(), card.end());

    for (int x : card)
    {
        int newJohn = john + x;
        int newMary = mary + x;
        if (newMary > 23)
        {
            cout << -1 << endl;
            return;
        }
        if (newJohn > 23 || newMary == 23)
        {
            cout << x << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
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