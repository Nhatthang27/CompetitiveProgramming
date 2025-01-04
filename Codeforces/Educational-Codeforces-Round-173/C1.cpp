void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int neg = 0, pos = 0, x = 0;
    vector<int> pref(n + 1);
    int pivot = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (abs(a[i]) != 1)
        {
            x = a[i];
            pivot = i;
        }
    }

    vector<int> res = {0};
    int sum = 0, glmn = 0, glmx = 0;
    int mn = 0, mx = 0, mxS = 0, mnS = 0;
    for (int i = 0; i < pivot; ++i)
    {
        sum += a[i];
        mx = max(mx, sum);
        mn = min(mn, sum);
        mxS = max(mxS, sum - mn);
        mnS = min(mnS, sum - mx);
    }
    dbg(mnS, mxS);
    for (int j = mnS; j <= mxS; ++j)
    {
        res.push_back(j);
    }
    sum = 0;
    mx = 0, mn = 0;
    mxS = 0, mnS = 0;
    for (int i = pivot + 1; i < n; ++i)
    {
        sum += a[i];
        mx = max(mx, sum);
        mn = min(mn, sum);
        mxS = max(mxS, sum - mn);
        mnS = min(mnS, sum - mx);
    }
    dbg(mnS, mxS);
    for (int j = mnS; j <= mxS; ++j)
    {
        res.push_back(j);
    }
    sum = 0;
    for (int i = pivot + 1; i < n; ++i)
    {
        sum += a[i];
        glmn = min(glmn, sum);
        glmx = max(glmx, sum);
    }
    sum = 0;
    mx = 0, mn = 0;
    for (int i = pivot - 1; i >= 0; --i)
    {
        sum += a[i];
        mx = max(mx, sum);
        mn = min(mn, sum);
    }
    glmx = max(glmx, glmx + mx);
    glmn = min(glmn, glmn + mn);
    dbg(glmn, glmx);
    for (int i = glmn; i <= glmx; ++i)
    {
        res.push_back(i + x);
    }
    sort(all(res));
    res.erase(unique(all(res)), res.end());
    cout << sz(res) << "\n";
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
}