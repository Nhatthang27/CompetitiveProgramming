
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
    string inp;
    cin >> inp;
    vector<int> a(n + 1);
    fu(i, 1, n)
    {
        a[i] = inp[i - 1] - '0';
    }
    // a is a  binary string
    vector<int> left(n + 1, 0), right(n + 1, 0);
    vector<int> left_1(n + 1, 0), right_1(n + 1, 0);
    vector<int> mi(n + 1, 0), ma(n + 1, 0);
    // a[i] = 1 -> left[i] is the number of 0s consecutively from the i to the left
    // a[i] = 1 -> right[i] is the number of 0s consecutively from the i to the right
    vector<int> l_index(n + 1, 0), r_index(n + 1, 0);

    int l_tmp_1 = 0;
    fu(i, 1, n)
    {
        if (a[i] == 1)
        {
            l_index[i] = l_tmp_1;
            l_tmp_1 = i;
        }
    }

    int r_tmp_1 = n + 1;
    fd(i, n, 1)
    {
        if (a[i] == 1)
        {
            r_index[i] = r_tmp_1;
            r_tmp_1 = i;
        }
    }

    left[1] = (a[1] == 0);
    right[n] = (a[n] == 0);
    fu(i, 2, n)
    {
        if (a[i] == 0)
        {
            left[i] = left[i - 1] + 1;
        }
        else
        {
            left_1[i] = left[i - 1];
            left[i] = 0;
        }
    }
    fd(i, n - 1, 1)
    {
        if (a[i] == 0)
        {
            right[i] = right[i + 1] + 1;
        }
        else
        {
            right_1[i] = right[i + 1];
            right[i] = 0;
        }
    }

    set<array<int, 3>> s;
    fu(i, 1, n)
    {
        if (a[i] == 0)
        {
            continue;
        }
        mi[i] = min(left_1[i], right_1[i]);
        ma[i] = max(left_1[i], right_1[i]);
        s.insert({mi[i], ma[i], i});
        // cout << mi[i] << " " << ma[i] << " " << i << endl;
    }

    // eacht time, reomve the element with the minimum distance and update the distance of the elements around it
    int ans = 0;
    while (s.size() > 0)
    {
        // for (auto x : mp)
        // {
        //     cerr << x.ff[0] << " " << x.ff[1] << " " << x.ff[2] << endl;
        // }
        // cerr << endl;
        ans = max(ans, (int)((*s.begin())[0] * (s.size() + 1) + s.size()));

        auto it = s.begin();
        int i = it->at(2);
        s.erase(it);

        if (s.empty())
        {
            break;
        }

        int pre_index = l_index[i];
        int next_index = r_index[i];
        if (pre_index >= 1)
        {
            // delete element in map has value pre_index
            // erase by value == pre_index
            s.erase({mi[pre_index], ma[pre_index], pre_index});

            right_1[pre_index] = right_1[pre_index] + right_1[i];
            // cout << pre_index << " " << right_1[pre_index] << endl;
            mi[pre_index] = min(left_1[pre_index], right_1[pre_index]);
            ma[pre_index] = max(left_1[pre_index], right_1[pre_index]);

            s.insert({mi[pre_index], ma[pre_index], pre_index});
            r_index[pre_index] = next_index;
            if (next_index <= n)
                l_index[next_index] = pre_index;
        }
        if (next_index <= n)
        {
            s.erase({mi[next_index], ma[next_index], next_index});

            left_1[next_index] = left_1[next_index] + left_1[i];
            mi[next_index] = min(left_1[next_index], right_1[next_index]);
            ma[next_index] = max(left_1[next_index], right_1[next_index]);

            s.insert({mi[next_index], ma[next_index], next_index});
            l_index[next_index] = pre_index;
            if (pre_index >= 1)
                r_index[pre_index] = next_index;
        }
    }
    cout << ans << endl;
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