
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
    string s;
    cin >> s;
    for(int i = 2; i < s.size(); i += 2) {
        if (s[i - 1] == '(') s[i] = ')';
    }
    for(int i = 0; i < s.size(); i++)
        if (s[i] == '_') s[i] = '(';
    stack<int> st;
    int res = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if (st.empty()) {
            st.push(i);
        } else {
            if (s[i] == ')') st.push(i);
            else {
                res += st.top() - i;
                st.pop();
            }
        }
    }
    cout << res << "\n";
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


