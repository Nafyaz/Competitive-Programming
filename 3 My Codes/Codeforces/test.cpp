#include <bits/stdc++.h>
using namespace std;
vector<int> v[26];
int cnt[26];
int main()
{
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++)
        v[s[i]-'a'].push_back(i);
    int ans=0;
    for (int i=0; i<26; i++)
    {
        int mx=0;
        for (int x=1; x<s.size(); x++)
        {
            memset(cnt,0,sizeof(cnt));
            int dis=0;
            for (int j=0; j<v[i].size(); j++)
            {
                char c=s[(v[i][j]+x)%s.size()];
                cnt[c-'a']++;
                if (cnt[c-'a']==1)
                    dis++;
                else if (cnt[c-'a']==2)
                    dis--;
            }
            mx=max(mx,dis);
        }
        ans+=mx;
    }
    printf("%.9lf",(double)ans/s.size());
}
