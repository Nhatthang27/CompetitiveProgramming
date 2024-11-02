
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve() {
    vector<int> limit(33);
    fu(i, 0, 32) cin >> limit[i];

    int n;
    map<pair<string, int>, int> mp;

    cin >> n;
    fu(i, 1, n) {
        string s;
        cin >> s;

        // split string by '.'
        vector<string> v;
        string tmp = "";
        for (char c : s) {
            if (c == '.') {
                v.push_back(tmp);
                tmp = "";
            } else {
                tmp += c;
            }
        }
        v.push_back(tmp);

        string new_s = "";
        for (string x : v) {
            // x is a number and convert it to binary
            int num = stoi(x);
            string binary = "";
            while (num > 0) {
                binary += (num % 2) + '0';
                num /= 2;
            }
            while (binary.size() < 8) {
                binary += '0';
            }
            reverse(binary.begin(), binary.end());
            new_s += binary;
        }

        bool ok = true;
        // map is store the number ip of each subnet
        // first is ip, second is subnet

        if (mp[{"", 0}] >= limit[0]) {
            ok = false;
        } else {
            for (int j = 0; j < new_s.size(); j++) {
                string ip = new_s.substr(0, j + 1);
                int subnet = j + 1;
                if (mp[{ip, subnet}] >= limit[subnet]) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            cout << "b\n";
        } else {
            cout << "a\n";
            mp[{"", 0}]++;
            for (int j = 0; j < new_s.size(); j++) {
                mp[{new_s.substr(0, j + 1), j + 1}]++;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0) {
        solve();
    }
}