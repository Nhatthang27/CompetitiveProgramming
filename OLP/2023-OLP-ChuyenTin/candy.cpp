
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e5 + 7;
int a[MAX];
int n, q;

array<int, 4> queries[MAX];

bool isSub1()
{
    return (n <= 200 && q <= 200);
}

bool isSub2()
{
    for (int i = 1; i <= q; i++)
    {
        if (queries[i][0] == 1)
            return false;
    }
    return true;
}

bool isSub3()
{
    for (int i = 1; i <= q; i++)
    {
        if (queries[i][0] == 2 && queries[i][3] != 1)
            return false;
    }
    return true;
}

void enter()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int id, newVal;
            cin >> id >> newVal;
            queries[i] = {type, id, newVal, -1};
        }
        else
        {
            int l, r, k;
            cin >> l >> r >> k;
            queries[i] = {type, l, r, k};
        }
    }
}

bool contain_k(int x, int k)
{
    while (x > 0)
    {
        if (x % 10 == k)
            return true;
        x /= 10;
    }
    return false;
}

void sub1()
{
    for (int q_i = 1; q_i <= q; q_i++)
    {
        if (queries[q_i][0] == 1)
        {
            int id = queries[q_i][1];
            int newVal = queries[q_i][2];
            a[id] = newVal;
        }
        else
        {
            int l = queries[q_i][1];
            int r = queries[q_i][2];
            int k = queries[q_i][3];
            int res = 0;
            for (int i = l; i <= r; i++)
            {
                if (i % k == 0)
                {
                    res += 2 * a[i];
                    continue;
                }
                if (contain_k(i, k))
                {
                    res += 2 * a[i];
                    continue;
                }
                res += a[i];
            }
            cout << res << "\n";
        }
    }
}

int new_a[10][MAX];
void sub2()
{
    for (int k = 1; k <= 9; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % k == 0 || contain_k(i, k))
            {
                new_a[k][i] = a[i] * 2;
            }
            else
            {
                new_a[k][i] = a[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            new_a[k][i] += new_a[k][i - 1];
        }
    }

    for (int i = 1; i <= q; i++)
    {
        auto [type, l, r, k] = queries[i];
        // cout << type << " " << l << " " << r << " " << k << "\n";
        cout << new_a[k][r] - new_a[k][l - 1] << "\n";
    }
}

struct SegmentTree
{
    vector<int> st;
    int n;

    SegmentTree(int _n)
    {
        n = _n;
        st.assign(4 * n, 0);
    }

    void update(int i, int l, int r, int pos, int val)
    {
        if (pos < l || pos > r)
            return;
        if (l == r)
        {
            st[i] = val;
            return;
        }
        int m = (l + r) / 2;
        update(i * 2, l, m, pos, val);
        update(i * 2 + 1, m + 1, r, pos, val);
        st[i] = st[i * 2] + st[i * 2 + 1];
    }

    int getSum(int i, int l, int r, int u, int v)
    {
        if (r < u || l > v)
            return 0;
        if (u <= l && r <= v)
            return st[i];
        int m = (l + r) / 2;
        int L = getSum(i * 2, l, m, u, v);
        int R = getSum(i * 2 + 1, m + 1, r, u, v);
        return L + R;
    }

    void update(int pos, int val)
    {
        update(1, 1, n, pos, val);
    }

    int getSum(int u, int v)
    {
        return getSum(1, 1, n, u, v);
    }
};

void sub3()
{
    SegmentTree st(n);
    for (int i = 1; i <= n; i++)
    {
        st.update(i, a[i]);
    }

    for (int i = 1; i <= q; i++)
    {
        if (queries[i][0] == 1)
        {
            int id = queries[i][1];
            int newVal = queries[i][2];
            st.update(id, newVal);
        }
        else
        {
            int l = queries[i][1];
            int r = queries[i][2];
            int k = queries[i][3];
            int res = st.getSum(l, r);
            cout << res * 2 << "\n";
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    if (isSub1())
    {
        sub1();
    }
    else if (isSub2())
    {
        sub2();
    }
    else
    {
        sub3();
    }
}