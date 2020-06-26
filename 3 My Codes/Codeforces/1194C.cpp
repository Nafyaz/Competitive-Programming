#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q, i, flag;
    string s, t, p;
    map<char, int> mp;

    scanf("%d", &q);
    while(q--)
    {
        mp.clear();
        flag = 1;

        cin >> s >> t >> p;

        for(i = 0; i < p.size(); i++)
            mp[p[i]] ++;

        flag = 1;
        while(!t.empty())
        {
            if(s[0] == t[0])
                s.erase(0, 1);
            else
            {
                if(mp[t[0]] == 0)
                {
                    flag = 0;
                    break;
                }
                mp[t[0]] --;
            }
            t.erase(0,1);
        }

        if(flag && s.empty() && t.empty())
            printf("YES\n");
        else
            printf("NO\n");
    }
}
