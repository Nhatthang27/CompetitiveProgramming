
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const vector<char> VOWELS = {'A', 'E', 'I', 'O', 'U', 'Y'};
const vector<char> CONSONANT = {'N', 'B', 'C', 'D', 'F', 'H', 'J', 'K', 'L', 'M', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z', 'Y', 'G'};

void solve()
{
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto c : s)
    {
        mp[c]++;
    }
    int ans = 0;
    string str_ans = "";
    int i_cs = 0;
    for (int i_vw = 0; i_vw < VOWELS.size(); i_vw++)
    {
        char vw = VOWELS[i_vw];
        while (mp[vw] > 0)
        {
            mp[vw]--;
            int cnt_cs = 0;
            string str_cs = "";
            while (cnt_cs < 2 && i_cs < CONSONANT.size())
            {
                char cs = CONSONANT[i_cs];
                if (mp[cs] == 0)
                {
                    i_cs++;
                    continue;
                }
                mp[cs]--;
                str_cs += cs;
                cnt_cs++;
            }
            if (cnt_cs == 2)
            {
                str_ans = str_ans + str_cs[0] + vw + str_cs[1];
                ans += 3;
            }
            else
            {
                if (cnt_cs == 1)
                    mp[str_cs[0]]++;
                break;
            }
        }
    }

    for (auto &c : str_ans)
    {
        if (mp['G'] == 0)
            break;
        if (c == 'N')
        {
            ans++;
            mp['G']--;
            continue;
        }
        if (find(VOWELS.begin(), VOWELS.end(), c) == VOWELS.end())
        {
            if (mp['N'] > 0 && mp['G'] > 0)
            {
                mp['N']--;
                mp['G']--;
                ans++;
            }
        }
    }
    cout << ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}