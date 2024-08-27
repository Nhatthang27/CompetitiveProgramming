#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b)  for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 1e5 + 7;

vector<ll> f(ll x) {
    vector<ll> res;
    if (x == 2) {
        res.push_back(0);
    } else if (x & 1) {
        res = f(x - 1);
        res.push_back(*min_element(res.begin(), res.end()) - 1);
    } else {
        res = f(x / 2);
        res.push_back(*max_element(res.begin(), res.end()) + 1);
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0),cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    ll t;
    cin >> t;
    while (t --> 0) {
        ll x;
        cin >> x;
        vector<ll> res = f(x);
        cout << res.size() << "\n";
        for(ll cc : res)  {
            cout << cc << " ";
        }
        cout << "\n";
    }
}


