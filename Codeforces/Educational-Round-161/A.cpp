#include<bits/stdc++.h>
#define ll long long
#define fu(i,a,b)  for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;

int main()   {
    ios_base::sync_with_stdio(0),cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t --> 0) {
        ll n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        bool res = false;
        fu(i, 0, n - 1) {
            if (a[i] != b[i]) {
                if (a[i] != c[i] && b[i] != c[i]) {
                    res = true;
                    break;
                }
            } else {
                if (c[i] != a[i]) {
                    res = true;
                    break;
                }
            }

        }
        if (res) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}
