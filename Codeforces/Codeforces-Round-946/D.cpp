
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
    int n;
    cin >> n;
    map<char, int> cnt;
    string s;
    cin >> s;

    for (char c : s) cnt[c]++;
    if (s == "NS" || s == "SN" || s == "EW" || s == "WE") {
        cout << "NO" << endl;
        return;
    }
    s = " " + s;
    int nor = cnt['N'];
    int eas = cnt['E'];
    int sou = cnt['S'];
    int wes = cnt['W'];
    if ((nor - sou) % 2 != 0 || (eas - wes) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    int sum1 = (nor - sou) / 2;
    vector<char> res(n + 1, ' ');
    if (sum1 > 0) {
        fu(i, 1, n) {
            if (s[i] == 'N' && sum1 > 0) {
                res[i] = 'H';
                sum1--;
            }
        }
    } else if (sum1 < 0) {
        fu(i, 1, n) {
            if (s[i] == 'S' && sum1 < 0) {
                res[i] = 'H';
                sum1++;
            }
        }
    } else {
        bool n_flag = false;
        bool s_flag = false;
        fu(i, 1, n) {
            if (s[i] == 'N' && !n_flag) {
                n_flag = true;
                res[i] = 'H';
            }
            if (s[i] == 'S' && !s_flag) {
                s_flag = true;
                res[i] = 'H';
            }
        }
    }
    fu(i, 1, n) {
        if (res[i] == ' ' && (s[i] == 'N' || s[i] == 'S')) {
            res[i] = 'R';
        }
    }
    int sum2 = (eas - wes) / 2;
    if (sum2 > 0) {
        fu(i, 1, n) {
            if (res[i] == ' ' && s[i] == 'E' && sum2 > 0) {
                res[i] = 'R';
                sum2--;
            }
        }
    } else if (sum2 < 0) {
        fu(i, 1, n) {
            if (res[i] == ' ' && s[i] == 'W' && sum2 < 0) {
                res[i] = 'R';
                sum2++;
            }
        }
    } else {
        bool e_flag = false;
        bool w_flag = false;
        fu(i, 1, n) {
            if (res[i] == ' ' && s[i] == 'E' && !e_flag) {
                e_flag = true;
                res[i] = 'R';
            }
            if (res[i] == ' ' && s[i] == 'W' && !w_flag) {
                w_flag = true;
                res[i] = 'R';
            }
        }
    }
    fu(i, 1, n) {
        if (res[i] == ' ' && (s[i] == 'E' || s[i] == 'W')) {
            res[i] = 'H';
        }
    }
    fu(i, 1, n) {
        cout << res[i];
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}