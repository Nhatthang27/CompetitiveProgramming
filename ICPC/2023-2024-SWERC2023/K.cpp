
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
using namespace __gnu_pbds;

// order set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// linkedlist c++
typedef list<int> li;
typedef list<int>::iterator lii;

void solve() {
    int n;
    cin >> n;

    ordered_set s;
    // s contains 1..n
    fu(i, 1, n) s.insert(i);

    vector<int> team1, team2;
    vector<int> choose1(n / 2 + 1), choose2(n / 2 + 1);

    fu(i, 1, n / 2) cin >> choose1[i];
    fu(i, 1, n / 2) cin >> choose2[i];

    fu(i, 1, n / 2) {
        auto it = *s.find_by_order(choose1[i] - 1);
        team1.push_back(it);
        s.erase(it);

        it = *s.find_by_order(choose2[i] - 1);
        team2.push_back(it);
        s.erase(it);
    }
    for (int x : team1) printf("%d ", x);
    printf("\n");
    for (int x : team2) printf("%d ", x);
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}