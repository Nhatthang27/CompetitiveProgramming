struct SegmentTree
{
    vector<int> minTree, maxTree;
    int n;

    SegmentTree(int size)
    {
        n = size;
        minTree.assign(4 * n, 1e18);
        maxTree.assign(4 * n, -1e18);
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
        }
    }

    void update(int id, int l, int r, int pos, int value)
    {
        if (l == r)
        {
            minTree[id] = value;
            maxTree[id] = value;
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
        }
    }

    int queryMin(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return 1e18;
        if (u <= l && r <= v)
            return minTree[id];
        int mid = (l + r) / 2;
        return min(queryMin(2 * id, l, mid, u, v), queryMin(2 * id + 1, mid + 1, r, u, v));
    }

    int queryMax(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return -1e18;
        if (u <= l && r <= v)
            return maxTree[id];
        int mid = (l + r) / 2;
        return max(queryMax(2 * id, l, mid, u, v), queryMax(2 * id + 1, mid + 1, r, u, v));
    }

    pair<int, int> queryMinMax(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return {-1e18, 1e18};
        if (u <= l && r <= v)
            return { minTree[id], maxTree[id] }
        int mid = (l + r) / 2;
        int left = queryMinMax(2 * id, l, mid, u, v);
        int right = queryMinMax(2 * id + 1, mid + 1, r, u, v);
        return {min(left.first, right.first), max(left.second, right.second)};
    }
};