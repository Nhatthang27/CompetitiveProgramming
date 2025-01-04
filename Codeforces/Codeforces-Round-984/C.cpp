
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    string s;
    int q;
    cin >> s >> q;
    set<int> st;

    fu(i, 0, (int)s.size() - 4) {
        string x = s.substr(i, 4);
        if (x == "1100") {
            st.insert(i);
            i += 3;
        }
    }
    // cout << "st.size() = " << st.size() << endl;

    while (q-- > 0) {
        int id, v;
        cin >> id >> v;
        id--;

        if (s[id] - '0' == v) {
            if (st.empty()) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            continue;
        }

        if (!st.empty()) {
            auto it = upper_bound(st.begin(), st.end(), id);
            if (it != st.end()) {
                if (it != st.begin()) {
                    auto prev = it;
                    prev--;
                    if (id >= *prev && id <= *prev + 3) {
                        st.erase(*prev);
                    }
                }
            } else {
                // compare with the last element
                auto last = st.rbegin();
                if (id >= *last && id <= *last + 3) {
                    st.erase(*last);
                }
            }
        }

        if (v == 1) {
            bool ok = true;
            s[id] = '1';
            if (id + 3 < s.size()) {
                string x = s.substr(id, 4);
                if (x == "1100") {
                    st.insert(id);
                    ok = false;
                }
            }
            if (id > 0 && ok == true) {
                string x = s.substr(id - 1, 4);
                if (x == "1100") {
                    st.insert(id - 1);
                }
            }

        } else {
            bool ok = true;
            s[id] = '0';
            if (id + 1 < s.size() && id > 1) {
                string x = s.substr(id - 2, 4);
                if (x == "1100") {
                    st.insert(id - 2);
                    ok = false;
                }
            }
            if (id < s.size() && id > 2 && ok == true) {
                string x = s.substr(id - 3, 4);
                if (x == "1100") {
                    st.insert(id - 3);
                }
            }
        }

        if (st.empty()) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}