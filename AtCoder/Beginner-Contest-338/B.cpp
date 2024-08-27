#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;

ll cnt[30];
char findS(string s) {
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    ll mx = 0;
    ll res = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > mx) {
            res = i;
            mx = cnt[i];
        }
    }
    return char('a' + res);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    string s;
    cin >> s;
    cout << (findS(s));
}


