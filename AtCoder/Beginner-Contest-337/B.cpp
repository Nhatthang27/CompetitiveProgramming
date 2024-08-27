#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i =a ; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;

ll findLast(char c, string s) {
    fd(i, s.size() - 1, 0) {
        if (s[i] == c) {
            return i;
        }
    }
    if (c == 'A') {
        return -3;
    } else if(c == 'B') {
        return -2;
    } else {
        return -1;
    }
}

int main() {
    string s;
    cin >> s;
    ll i = 0;
    while(i < s.size() && s[i] == 'A') {
        i++;
    }
    while(i < s.size() && s[i] == 'B') {
        i++;
    }
    while(i < s.size() && s[i] == 'C') {
        i++;
    }
    if (i == s.size()) {
        cout << "Yes";
    } else {
        cout << "No";
    }

}

