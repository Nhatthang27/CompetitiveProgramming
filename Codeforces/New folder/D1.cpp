#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegmentTree
{
    vector<int> minTree, maxDiffTree, maxTree;
    int n;

    SegmentTree(int size)
    {
        n = size;
        minTree.assign(4 * n, 1e18);
        maxTree.assign(4 * n, -1e18);
        maxDiffTree.assign(4 * n, -1e18);
    }

    void build(int id, int l, int r, const vector<int> &a)
    {
        if (l == r)
        {
            minTree[id] = a[l];
            maxTree[id] = a[l];
            maxDiffTree[id] = 0;
        }
        else
        {
            int mid = (l + r) / 2;
            build(2 * id, l, mid, a);
            build(2 * id + 1, mid + 1, r, a);
            minTree[id] = min(minTree[2 * id], minTree[2 * id + 1]);
            maxTree[id] = max(maxTree[2 * id], maxTree[2 * id + 1]);
            maxDiffTree[id] = max(maxDiffTree[2 * id], maxDiffTree[2 * id + 1]);
            maxDiffTree[id] = max(maxDiffTree[id], maxTree[2 * id + 1] - minTree[2 * id]);
        }
    }

    void update(int id, int l, int r, int pos, int value)
    {
        if (l == r)
        {
            minTree[id] = value;
            maxTree[id] = value;
            maxDiffTree[id] = 0;
        }
        else
        {
            int mid = (l + r) / 2;
            if (pos <= mid)
                update(2 * id, l, mid, pos, value);
            else
                update(2 * id + 1, mid + 1, r, pos, value);
            minTree[id] = min(minTree[2 * id], minTree[2 * id + 1]);
            maxTree[id] = max(maxTree[2 * id], maxTree[2 * id + 1]);
            maxDiffTree[id] = max(maxDiffTree[2 * id], maxDiffTree[2 * id + 1]);
            maxDiffTree[id] = max(maxDiffTree[id], maxTree[2 * id + 1] - minTree[2 * id]);
        }
    }

    int queryMaxDiff()
    {
        return maxDiffTree[1];
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        a[i] -= (i + 1);
        b[i] += (i + 1);
    }
    reverse(b.begin(), b.end());

    SegmentTree st_a(n), st_b(n);
    st_a.build(1, 0, n - 1, a);
    st_b.build(1, 0, n - 1, b);
    int ans = max(st_a.queryMaxDiff(), st_b.queryMaxDiff());
    // int ans = st_a.queryMaxDiff();
    // int mi = b[n - 1];
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     ans = max(ans, b[i] - mi);
    //     mi = min(mi, b[i]);
    // }
    cout << ans << "\n";
    for (int turn = 0; turn < q; turn++)
    {
        int pos, newVal;
        cin >> pos >> newVal;
        pos--;
        a[pos] = newVal - (pos + 1);
        // b[pos] = newVal + (pos + 1);
        b[n - pos - 1] = newVal + (pos + 1);

        st_a.update(1, 0, n - 1, pos, a[pos]);
        st_b.update(1, 0, n - 1, n - pos - 1, b[n - pos - 1]);

        ans = max(st_a.queryMaxDiff(), st_b.queryMaxDiff());
        // int mi = b[n - 1];
        // int ans = st_a.queryMaxDiff();
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     ans = max(ans, b[i] - mi);
        //     mi = min(mi, b[i]);
        // }

        cout << ans << "\n";
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
