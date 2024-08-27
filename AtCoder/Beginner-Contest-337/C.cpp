#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i =a ; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 3e5 + 7;

ll order[MAX], bef[MAX];
ll cal(ll i) {
    if (order[i] != -1) {
        return order[i];
    }
    return order[i] = cal(bef[i]) + 1;
}


int main() {
    ll n;
//    freopen("input.inp", "r", stdin);
    cin >> n;
    fu(i, 1, n) {
        cin >> bef[i];
        if (bef[i] == -1) {
            order[i] = 1;
        } else {
            order[i] = -1;
        }
    }
    fu(i, 1, n) {
        if (order[i] == -1) {
            cal(i);
        }
    }
    vector<pair<ll, ll>> res;
    fu(i, 1, n) {
        res.push_back(make_pair(order[i], i));
    }
    sort(res.begin(), res.end());
    for(pair<ll, ll> x : res) {
        cout << x.second << " ";
    }
}

