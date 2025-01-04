#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define each(x, a) for (auto &x : a)

#define ll long long

const int N = 2e5;
#define all(a) begin(a), end(a)
#define sz(a) a.size()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    each(x, v) {
        int k;
        cin >> k;
        x.resize(k);
        each(y, x) cin >> y, --y;
    }

    vector<int> ind(n);
    iota(begin(ind), end(ind), 0);
    sort(begin(ind), end(ind),
         [&](auto a, auto b) { return v[a].size() > v[b].size(); });

    vector<int> vm(m, -1);

    rep(i, 0, n) {

        auto x = ind[i];
        int lst = -2;
        each(y, v[x]) {
            if (lst == -2) {
                lst = vm[y];
            }

            if (lst != vm[y]) {
                std::cout << "YES" << '\n';
                if (lst == -1)
                    lst = vm[y];

                if (vm[y] != -1 && v[vm[y]].size() < v[lst].size())
                    lst = vm[y];

                std::cout << lst + 1 << ' ' << x + 1 << '\n';
                return;
            }

            vm[y] = x;
        }
    }
    std::cout << "NO" << '\n';
}

int main() {
    solve();
    return 0;
}