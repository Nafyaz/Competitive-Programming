#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, paren = 0, maxl = 0, maxw = 0, l = 0, w = 0;
    scanf("%d", &n);
    char s[260];
    scanf("%s", s);

    FORAB(i, 0, n)
    {
        if(s[i] == '(')
        {
            paren = 1;
            //w = 0;
            continue;
        }
        if(s[i] == ')')
        {
            paren = 0;
            if(s[i - 1] != '(' && s[i - 1] != '_')
                w++;
            if(maxw < w)
                maxw = w;
            continue;
        }
        if(paren == 1 && s[i] == '_' && s[i - 1] != '_' && s[i - 1] != '(')
            w++;
    }

    FORAB(i, 0, n)
    {
        if(s[i] == '(')
        {
            paren = 1;
            if(l > maxl)
                maxl = l;
            l = 0;
            continue;
        }
        if(s[i] == ')')
        {
            paren = 0;
            continue;
        }
        if(paren == 0)
        {
            if(s[i] == '_')
            {
                if(l > maxl)
                    maxl = l;
                l = 0;
            }
            else
                l++;
        }
    }
    if(l > maxl)
        maxl = l;
    printf("%d %d\n", maxl, w);
}
