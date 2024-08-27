#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i =a ; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll s1, s2;
    s1 = s2 = 0;
    fu(i, 1, n) {
        ll x, y;
        cin >> x >> y;
        s1 += x;
        s2 += y;
    }
    if (s1 == s2) {
        cout << "Draw";
    } else if (s1 > s2){
        cout << "Takahashi";
    } else {
        cout << "Aoki";
    }

}
