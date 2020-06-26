#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, flag, scount, tcount;
    char c;
    scanf("%d", &n);
    string s, t;
    while(n--)
    {
        flag = 1;
        cin >> s >> t;
        i = j = 0;
        while(i < s.size() && j < t.size())
        {
            c = s[i];
            scount = 0;
            tcount = 0;
            while(i < s.size() && s[i] == c)
            {
                scount++;
                i++;
            }
            while(j < t.size() && t[j] == c)
            {
                tcount++;
                j++;
            }
            if(tcount < scount)
                flag = 0;
        }
        if(i != s.size() || j != t.size())
            flag = 0;

        flag ? printf("YES\n") : printf("NO\n");
    }
}
