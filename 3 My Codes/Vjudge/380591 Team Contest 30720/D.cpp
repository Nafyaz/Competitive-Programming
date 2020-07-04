#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j, n, m;
    string s, c, p;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cin >> s >> c >> p;
        map<char, int> mp;

        for(i = 0; i < n; i++)
        {
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = c[i] - '0';
            else
                mp[s[i]] = min(mp[s[i]], c[i] - '0');
        }

        int ans = 0;
        for(i = 0; i < m; i++)
        {
            if(mp.find(p[i]) == mp.end())
            {
                ans = -1;
                break;
            }
            else
                ans += mp[p[i]];
        }

        cout << ans << endl;
    }
}
