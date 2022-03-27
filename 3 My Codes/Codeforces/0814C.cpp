#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, q, i, j, m, c, len, need;
    string s;
    ll pref[27][1502] = {0}, ans[1502][27] = {0};

    cin >> n >> s;

    for(c = 0; c < 26; c++)
    {
        for(j = 1; j <= n; j++)
            pref[c][j] = pref[c][j-1] + (s[j-1]-'a' == c);
    }

    for(c = 0; c < 26; c++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j++)
            {
                len = j-i+1;
                need = len - pref[c][j] + pref[c][i-1];
                ans[need][c] = max(ans[need][c], len);
            }
        }
    }

    for(c = 0; c < 26; c++)
    {
        for(i = 1; i <= n; i++)
            ans[i][c] = max(ans[i-1][c], ans[i][c]);
    }

    cin >> q;
    while(q--)
    {
        cin >> m >> s;
        cout << ans[m][s[0]-'a'] << "\n";
    }
}
